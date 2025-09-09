#include "../include/Doctor.h"
#include <iostream>
#include <limits>

Doctor::Doctor() : doctorID(0), isAvailable(true) {}

void Doctor::inputDetails() {
    std::cout << "Enter Doctor ID: ";
    std::cin >> doctorID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Specialization: ";
    std::getline(std::cin, specialization);

    isAvailable = true;
}

void Doctor::displayDetails() {
    std::cout << "\nDoctor Details:\n";
    std::cout << "ID: " << doctorID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Specialization: " << specialization << "\n";
    std::cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
}