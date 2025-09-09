#include "../include/Appointment.h"
#include <iostream>

Appointment::Appointment() : appointmentID(0), patientID(0), doctorID(0), status("Scheduled") {}

Appointment::Appointment(int aID, int pID, int dID) 
    : appointmentID(aID), patientID(pID), doctorID(dID), status("Scheduled") {}

void Appointment::displayDetails() {
    std::cout << "\nAppointment Details:\n";
    std::cout << "Appointment ID: " << appointmentID << "\n";
    std::cout << "Patient ID: " << patientID << "\n";
    std::cout << "Doctor ID: " << doctorID << "\n";
    std::cout << "Status: " << status << "\n";
}