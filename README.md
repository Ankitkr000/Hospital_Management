# Hospital Management System (C++)

## Overview
A console-based Hospital Management System implemented in C++ demonstrating:
- Object-Oriented Programming (Classes, Inheritance, Polymorphism)
- Emergency and Regular Patients handling
- Doctor assignment to emergency patients
- Appointment management
- File-based persistence with `.txt` files

## Features
1. Add Patients (Regular & Emergency)
2. Add Doctors
3. Show all Patients
4. Show all Doctors
5. Assign available Doctor to Emergency Patient
6. Show Appointments
7. Update Appointment Status
8. Data persistence in `.txt` files

## File Structure
- `src/` : C++ source code
- `include/` : Header files
- `data/` : Text files for storing data
- `build/` : Compiled executable (optional)
- `README.md` : Project description

## How to Run
1. Compile the project using:
   ```bash
   g++ src/*.cpp -Iinclude -o build/Hospital.exe
