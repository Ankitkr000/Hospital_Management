#include "../include/Patient.h"
#include <iostream>
#include <limits>

Patient::Patient() : patientID(0), age(0), isEmergency(false) {}

void Patient::inputDetails() {
    std::cout << "Enter Patient ID: ";
    std::cin >> patientID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Gender: ";
    std::getline(std::cin, gender);

    std::cout << "Enter Ailment: ";
    std::getline(std::cin, ailment);

    std::cout << "Is Emergency (1-Yes, 0-No): ";
    int e;
    std::cin >> e;
    isEmergency = (e == 1);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Patient::displayDetails() {
    std::cout << "\nPatient Details:\n";
    std::cout << "ID: " << patientID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Gender: " << gender << "\n";
    std::cout << "Ailment: " << ailment << "\n";
    std::cout << "Emergency: " << (isEmergency ? "Yes" : "No") << "\n";
}

void Patient::treatmentDetails() {
    std::cout << "Regular treatment for " << ailment << "\n";
}