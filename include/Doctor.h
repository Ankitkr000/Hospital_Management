#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
private:
    int doctorID;
    std::string name;
    std::string specialization;
    bool isAvailable;

public:
    Doctor();
    void inputDetails();
    void displayDetails();

    // Getters
    int getDoctorID() const { return doctorID; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    bool getAvailability() const { return isAvailable; }

    // Setters
    void setDoctorID(int id) { doctorID = id; }
    void setName(const std::string& n) { name = n; }
    void setSpecialization(const std::string& spec) { specialization = spec; }
    void setAvailability(bool status) { isAvailable = status; }
};

#endif