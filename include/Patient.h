#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
protected:
    int patientID;
    std::string name;
    int age;
    std::string gender;
    std::string ailment;
    bool isEmergency;

public:
    Patient();
    virtual ~Patient() = default;
    virtual void inputDetails();
    virtual void displayDetails();
    virtual void treatmentDetails();

    // Getters
    int getPatientID() const { return patientID; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    std::string getAilment() const { return ailment; }
    bool getIsEmergency() const { return isEmergency; }

    // Setters
    void setPatientID(int id) { patientID = id; }
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(const std::string& g) { gender = g; }
    void setAilment(const std::string& a) { ailment = a; }
    void setIsEmergency(bool e) { isEmergency = e; }
};

#endif