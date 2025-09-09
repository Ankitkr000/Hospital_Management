#include <fstream>
#include <sstream>
#include "Patient.h"
#include "EmergencyPatient.h"
#include "Doctor.h"
#include "Appointment.h"

#include <iostream>
#include <vector>
#include <limits>

// ------------------- File Operations -------------------

// Load Patients from file
void loadPatients(std::vector<Patient*>& patients) {
    std::ifstream file("patients.txt");
    if (!file.is_open()) return;

    int id, age, severity;
    bool isEmergency;
    std::string name, gender, ailment, emergencyContact;

    while (file >> id >> age >> isEmergency) {
        // ... existing code ...
        if (isEmergency) {
            EmergencyPatient* ep = new EmergencyPatient();
            ep->setPatientID(id);
            ep->setAge(age);
            ep->setName(name);
            ep->setGender(gender);
            ep->setAilment(ailment);
            ep->setIsEmergency(true);
            file >> severity;
            ep->setSeverity(severity);  // Now accepts int
            std::getline(file, emergencyContact, '|');
            ep->setEmergencyContact(emergencyContact);
            patients.push_back(ep);
        } else {
            // ... existing code for regular patients ...
        }
    }
    file.close();
}

// Save Patients to file
void savePatients(const std::vector<Patient*>& patients) {
    std::ofstream file("patients.txt");
    file << "ID\tName\tAge\tGender\tAilment\tEmergency\tContact\tSeverity\n"; // Header
    for (auto* p : patients) {
        EmergencyPatient* ep = dynamic_cast<EmergencyPatient*>(p);
        file << p->getPatientID() << "\t"
             << p->getName() << "\t"
             << p->getAge() << "\t"
             << p->getGender() << "\t"
             << p->getAilment() << "\t"
             << (p->getIsEmergency() ? "Yes" : "No") << "\t";

        if (ep && ep->getIsEmergency()) {
            file << ep->getEmergencyContact() << "\t"
                 << ep->getSeverityString() << "\n";
        } else {
            file << "-\t-\n";
        }
    }
}


// Load Doctors
void loadDoctors(std::vector<Doctor>& doctors) {
    std::ifstream file("doctors.txt");
    if (!file.is_open()) return;

    int id;
    std::string name, specialization;
    
    while (file >> id) {
        Doctor d;
        d.setDoctorID(id);
        std::getline(file >> std::ws, name, '|');
        d.setName(name);
        std::getline(file, specialization, '|');
        d.setSpecialization(specialization);
        doctors.push_back(d);
    }
    file.close();
}

// Save Doctors
void saveDoctors(const std::vector<Doctor>& doctors) {
    std::ofstream file("doctors.txt");
    file << "ID\tAvailability\tName\tSpecialization\n"; // Header
    for (auto& d : doctors) {
        file << d.getDoctorID() << "\t"
             << (d.getAvailability() ? "Yes" : "No") << "\t"
             << d.getName() << "\t"
             << d.getSpecialization() << "\n";
    }
}


// Load Appointments
void loadAppointments(std::vector<Appointment>& appointments) {
    std::ifstream file("appointments.txt");
    if (!file) return;

    int aID, pID, dID;
    std::string status;
    while (file >> aID >> pID >> dID) {
        file.ignore(); // ignore space
        std::getline(file, status);
        Appointment ap(aID, pID, dID);
        ap.setStatus(status);
        appointments.push_back(ap);
    }
}

// Save Appointments
void saveAppointments(const std::vector<Appointment>& appointments) {
    std::ofstream file("appointments.txt");
    file << "AppointmentID\tPatientID\tDoctorID\tStatus\n"; // Header
    for (auto& a : appointments) {
        file << a.getAppointmentID() << "\t"
             << a.getPatientID() << "\t"
             << a.getDoctorID() << "\t"
             << a.getStatus() << "\n";
    }
}


// ------------------- Main Program -------------------

int main() {
    std::vector<Patient*> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;

    int choice, appointmentCounter = 1;

    // 🔹 Load existing data
    loadPatients(patients);
    loadDoctors(doctors);
    loadAppointments(appointments);

    do {
        std::cout << "\n===== Hospital Management System =====\n";
        std::cout << "1. Add Patient\n";
        std::cout << "2. Add Doctor\n";
        std::cout << "3. Show All Patients\n";
        std::cout << "4. Show All Doctors\n";
        std::cout << "5. Assign Doctor to Emergency Patient\n";
        std::cout << "6. Show Appointments\n";
        std::cout << "7. Update Appointment Status\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int isEmergency;
            std::cout << "Is this patient an Emergency? (1-Yes, 0-No): ";
            std::cin >> isEmergency;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Patient* p;
            if (isEmergency)
                p = new EmergencyPatient();
            else
                p = new Patient();

            p->inputDetails();
            patients.push_back(p);
            savePatients(patients);  // 🔹 Save immediately
            break;
        }

        case 2: {
            Doctor d;
            d.inputDetails();
            doctors.push_back(d);
            saveDoctors(doctors);  // 🔹 Save immediately
            break;
        }

        case 3: {
            for (auto* p : patients) {
                p->displayDetails();
                p->treatmentDetails();
                std::cout << "-------------------------\n";
            }
            break;
        }

        case 4: {
            for (auto& d : doctors) {
                d.displayDetails();
                std::cout << "-------------------------\n";
            }
            break;
        }

        case 5: {
            bool foundEmergency = false;
            for (auto* p : patients) {
                EmergencyPatient* ep = dynamic_cast<EmergencyPatient*>(p);
                if (ep && ep->getIsEmergency()) {
                    foundEmergency = true;
                    bool assigned = false;
                    for (auto& d : doctors) {
                        if (d.getAvailability()) {
                            d.setAvailability(false);
                            appointments.push_back(Appointment(
                                appointmentCounter++,
                                ep->getPatientID(),
                                d.getDoctorID()
                            ));
                            std::cout << "✅ Doctor assigned to emergency patient!\n";
                            assigned = true;
                            saveDoctors(doctors);
                            saveAppointments(appointments); // 🔹 Save immediately
                            break;
                        }
                    }
                    if (!assigned)
                        std::cout << "⚠️ No doctors available right now!\n";
                }
            }
            if (!foundEmergency) {
                std::cout << "⚠️ No emergency patients found!\n";
            }
            break;
        }

        case 6: {
            if (appointments.empty()) {
                std::cout << "⚠️ No appointments available!\n";
            } else {
                for (auto& ap : appointments) {
                    ap.displayDetails();
                    std::cout << "-------------------------\n";
                }
            }
            break;
        }

        case 7: {
            if (appointments.empty()) {
                std::cout << "⚠️ No appointments to update!\n";
                break;
            }

            int apID;
            std::cout << "Enter Appointment ID to update: ";
            std::cin >> apID;

            bool found = false;
            for (auto& ap : appointments) {
                if (ap.getAppointmentID() == apID) {
                    found = true;
                    std::cout << "Enter new status (Scheduled/Completed/Cancelled): ";
                    std::string status;
                    std::cin.ignore();
                    std::getline(std::cin, status);
                    ap.setStatus(status);
                    std::cout << "✅ Appointment updated successfully!\n";
                    saveAppointments(appointments); // 🔹 Save immediately
                    break;
                }
            }
            if (!found) {
                std::cout << "⚠️ Appointment not found!\n";
            }
            break;
        }

        case 8:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    // Free memory for patients
    for (auto* p : patients) {
        delete p;
    }

    return 0;
}
