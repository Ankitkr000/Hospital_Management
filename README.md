# Hospital Management System (C++)

## Overview
This is a **console-based Hospital Management System** implemented in C++, demonstrating:

- Object-Oriented Programming (Classes, Inheritance, Polymorphism)  
- Handling of Emergency and Regular Patients  
- Doctor assignment to emergency patients  
- Appointment management  
- File-based persistence using `.txt` files  

---

## Features
The system includes the following features:

- **Add Patients**: Add regular or emergency patients  
- **Add Doctors**: Add new doctors to the system  
- **Show All Patients**: Display all patient records  
- **Show All Doctors**: Display all doctor records  
- **Assign Doctor to Emergency Patients**: Automatically assign available doctors to emergency patients  
- **Show Appointments**: Display all scheduled appointments  
- **Update Appointment Status**: Change the status of appointments (Scheduled, Completed, Cancelled)  
- **Persistent Storage**: All data is stored in `.txt` files inside the `data/` folder  

---


## Project Structure
```
CPP-Hospital-Management/
├── src/          # C++ source code (.cpp files)
├── include/      # Header files (.h)
├── data/         # Text files storing persistent data
│   ├── patients.txt
│   ├── doctors.txt
│   └── appointments.txt
├── build/        # Compiled executable (optional)
├── .gitignore    # Git ignore file
└── README.md     # Project description and instructions
```


## How to Run Locally

Follow these steps to run the Hospital Management System on your local machine:

### Step 1: Clone the Repository
First, clone the repository to your local machine:

```bash
git clone https://github.com/Ankitkr000/Hospital_Management.git
cd CPP-Hospital-Management

## Step 2: Compile the Project

Make sure you have g++ installed. Then, compile the project using the following command:


FOR WINDOWS OPERATING SYSTEM - 
g++ src/*.cpp -Iinclude -o build/Hospital.exe

## Step 3: Run the Executable

Run the compiled program:

build/Hospital.exe

The console will display the menu:

===== Hospital Management System =====
1. Add Patient
2. Add Doctor
3. Show All Patients
4. Show All Doctors
5. Assign Doctor to Emergency Patient
6. Show Appointments
7. Update Appointment Status
8. Exit
Enter choice:

## Step 4: Use the System

Add Patient: Add a new patient (Emergency or Regular). Emergency patients require severity and emergency contact details.

Add Doctor: Add a new doctor with ID, name, and specialization.

Show All Patients / Doctors: Display all stored records.

Assign Doctor to Emergency Patient: Automatically assign an available doctor to emergency patients.

Show Appointments: Display all scheduled appointments.

Update Appointment Status: Update the status of any appointment (Scheduled, Completed, Cancelled).

## Step 5: Data Persistence

All changes (patients, doctors, appointments) are automatically saved in .txt files inside the data/ folder:

data/patients.txt

data/doctors.txt

data/appointments.txt
