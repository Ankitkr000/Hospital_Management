#ifndef EMERGENCY_PATIENT_H
#define EMERGENCY_PATIENT_H

#include "Patient.h"

class EmergencyPatient : public Patient {
private:
    std::string emergencyContact;
    int severity;  // Changed to int for easier loading/saving

public:
    EmergencyPatient();
    void inputDetails() override;
    void displayDetails() override;
    void treatmentDetails() override;

    // Getters
    std::string getEmergencyContact() const { return emergencyContact; }
    int getSeverity() const { return severity; }
    
    // Setters
    void setEmergencyContact(const std::string& contact) { emergencyContact = contact; }
    void setSeverity(int sev) { severity = sev; }
    
    // Helper function to convert severity number to string
    std::string getSeverityString() const;
};

#endif