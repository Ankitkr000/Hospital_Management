#include "../include/EmergencyPatient.h"
#include <iostream>
#include <limits>

EmergencyPatient::EmergencyPatient() : severity(0) {
    isEmergency = true;
}

void EmergencyPatient::inputDetails() {
    Patient::inputDetails();
    
    std::cout << "Enter Emergency Contact: ";
    std::getline(std::cin, emergencyContact);

    std::cout << "Enter Severity (1-Critical, 2-Serious, 3-Moderate): ";
    std::cin >> severity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void EmergencyPatient::displayDetails() {
    Patient::displayDetails();
    std::cout << "Emergency Contact: " << emergencyContact << "\n";
    std::cout << "Severity: " << getSeverityString() << "\n";
}

void EmergencyPatient::treatmentDetails() {
    std::cout << "EMERGENCY treatment required for " << ailment << "\n";
    std::cout << "Severity Level: " << getSeverityString() << "\n";
}

std::string EmergencyPatient::getSeverityString() const {
    switch(severity) {
        case 1: return "Critical";
        case 2: return "Serious";
        case 3: return "Moderate";
        default: return "Unknown";
    }
}