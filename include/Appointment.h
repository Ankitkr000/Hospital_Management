#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
private:
    int appointmentID;
    int patientID;
    int doctorID;
    std::string status;

public:
    Appointment();
    Appointment(int aID, int pID, int dID);
    void displayDetails();

    // Getters
    int getAppointmentID() const { return appointmentID; }
    int getPatientID() const { return patientID; }
    int getDoctorID() const { return doctorID; }
    std::string getStatus() const { return status; }

    // Setter
    void setStatus(const std::string& newStatus) { status = newStatus; }
};

#endif