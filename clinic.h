///////////////////////////////////////////////////////////////////////////
// Assignment 1 - Milestone 3
// Full Name  : Mustafa Dohad
// Student ID#: 123090235
// Email      : mna26@myseneca.ca
// Section    : ZGG
//
// Authenticity Declaration:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

#ifndef CLINIC_H
#define CLINIC_H

//////////////////////////////////////
// Module macros (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACROS !!!
#define FORMATFORM 1
#define FORMAT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

// Additional Macros for Milestone 3
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 29
#define MIN_HOUR 10
#define MAX_HOUR 14
#define MIN_INTERVAL 30

//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
struct Phone
{
    char description[PHONE_DESC_LEN + 1]; // for string a CString
    char number[PHONE_LEN + 1];           // for storing a CString
};

// Data type: Patient
struct Patient
{
    int patientNumber;
    char name[NAME_LEN + 1]; // for storing a CString
    struct Phone phone;
};

// Data type: Time
struct Time
{
    int hour;
    int min;
};

// Data type: Date
struct Date
{
    int year;
    int month;
    int day;
};

// Data type: Appointment
struct Appointment
{
    int patientNumber;
    struct Date date;
    struct Time time;
};

// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient *patients;
    int maxPatient;
    struct Appointment *appointments;
    int maxAppointments;
};

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FORMATFORM | FORMAT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt);

// Display appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords);

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField);

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData *data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient *patient);

// Menu: Appointment Management
void menuAppointment(struct ClinicData *data);

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! ALL the below functions need defining       !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!! DO NOT MODIFY THE BELOW PROTOTYPES !!!

// Display all patient data in FORMATFORM | FORMAT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt);

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max);

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max);

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max);

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max);

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData *data);

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData *data);

// Add an appointment record to the appointment array
void addAppointment(struct Appointment appointment[], int maxAppointments, struct Patient *patient, int maxPatients);

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment *appointment, int maxAppointments, struct Patient *patient, int maxPatients);

// Sorting the appointments according to the order of appointment scheduling time
void sortAppointments(struct Appointment appointments[], int max);

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);

// To find if the time slot is available
int timeSlot(struct Date date, struct Time time, struct Appointment *appointment, int max);

// To find the next slot available
int nextSlot(struct Appointment *appointment, int max);

// To see the validity of an appointment
int appointmentValidity(int patientNumber, struct Date date, struct Appointment *appointment, int max);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient);

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone);

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char *datafile, struct Patient patients[], int max);

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char *datafile, struct Appointment appoints[], int max);

#endif // !CLINIC_H#pragma once
