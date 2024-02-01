/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//include the string library functions
#include<string.h>


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FORMATFORM | FORMAT_TABLE format
void displayPatientData(const struct Patient* patient, int format)
{
    if (format == FORMATFORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FORMAT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}





// -------------------------------------------------------------------------- -
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FORMATFORM | FORMAT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int format)
{
    int i, recordCount = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber != 0) //displays the data for non-zero patientID
        {
            displayPatientData(&patient[i], format);
            recordCount = 1; //changing the value of flag
        }
    }
    if (recordCount == 0)
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}




// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int searchChoice;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &searchChoice); //making the selection choice
        printf("\n");
        if (searchChoice == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();

        }
        else if (searchChoice == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();

        }
    } while (searchChoice != 0); //loop runs until the user enters 0

}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int quitLoop, arrayIndex, returnValue;
    int i = 0;

    // Checking for first empty space
    do {
        quitLoop = 0;
        if (patient[i].patientNumber == 0)
        {
            quitLoop = 1;
            arrayIndex = i;
        }
        i++;
    } while (i < max && quitLoop == 0);

    if (quitLoop == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        // Assigning the value
        returnValue = nextPatientNumber(patient, max);
        patient[arrayIndex].patientNumber = returnValue;
        inputPatient(&patient[arrayIndex]);
        printf("*** New patient record added ***\n\n");
    }
}
/*void addPatient(struct Patient patient[], int max)
{
    int i, arrayIndex, recordCount = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0) //checking an empty record
        {
            arrayIndex = i;
            recordCount++;
            break;

        }
    }
    if (recordCount != 0)
    {
        patient[arrayIndex].patientNumber = nextPatientNumber(patient, max); //storing the next patient number
        inputPatient(&patient[arrayIndex]);
        printf("*** New patient record added ***\n\n");
    }

    if (recordCount == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}*/


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientID, returnValue;
    printf("Enter the patient number: ");
    scanf("%d", &patientID);
    printf("\n");
    returnValue = findPatientIndexByPatientNum(patientID, patient, max); //collecting the return value that can be -1 or 1
    if (returnValue == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[returnValue]);
    }

}



// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientID, returnValue, quitLoop = 1;
    char removeChoice, ch;
    printf("Enter the patient number: ");
    scanf("%d", &patientID);
    printf("\n");
    returnValue = findPatientIndexByPatientNum(patientID, patient, max); //collecting the return value that can be -1 or 1
    if (returnValue == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();

    }
    else
    {
        printf("Name  : %s\n", patient[returnValue].name);
        printf("Number: %05d\n", patient[returnValue].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[returnValue].phone.number); //calling the function to display the phone number
        printf(" (%s)\n\n", patient[returnValue].phone.description);
        printf("Are you sure you want to remove this patient record? (y/n): ");
        do
        {
            scanf(" %c%c", &removeChoice, &ch);
            if ((removeChoice == 'n' || removeChoice == 'N') && (ch == '\n')) {
                printf("Operation aborted.\n\n");
                quitLoop = 0;
                clearInputBuffer();
            }
            else if ((removeChoice == 'y' || removeChoice == 'Y') && (ch == '\n')) {
                // Assigning patient to safe empty state so that the other function can't access it
                patient[returnValue].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                quitLoop = 0;
            }
            else {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (quitLoop);
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 additional functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//Function to sort the appointments
void sortAppointments(struct Appointment appointments[], int max) {
    int i, j;
    struct Appointment temp;

    // Converting all the value to a common measure of minutes
    for (i = 0; i < max; i++) {
        appointments[i].time.min = (appointments[i].date.year * 12 * 30 * 24 * 60) + (appointments[i].date.month * 30 * 24 * 60) + (appointments[i].date.day * 24 * 60) + (appointments[i].time.hour * 60) + appointments[i].time.min;
    }

    // Using bubble sort to sort the records
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appointments[j].time.min > appointments[j + 1].time.min)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }

    // Converting time back to minutes
    for (i = 0; i < max; i++) {
        appointments[i].time.min = appointments[i].time.min - (appointments[i].date.year * 12 * 30 * 24 * 60) - (appointments[i].date.month * 30 * 24 * 60) - (appointments[i].date.day * 24 * 60) - (appointments[i].time.hour * 60);
    }

}
//Function to see if there is any time slot available
int timeSlot(struct Date date, struct Time time, struct Appointment* appointment, int max)
{
    int i, slotAvailability = 0;
    for (i = 0; i < max; i++)
    {
        //checking if the time matches with the time of any particular record
        if (date.year == appointment[i].date.year && date.month == appointment[i].date.month && date.day == appointment[i].date.day && time.hour == appointment[i].time.hour && time.min == appointment[i].time.min)
        {
            slotAvailability = 1;
        }
    }
    return slotAvailability; //returning the result about availability
}


//Function to see the next slot available
int nextSlot(struct Appointment* appointment, int max)
{
    int i, slotAvailability = 0;
    for (i = 0; i < max && slotAvailability == 0; i++)
    {
        //checking if there is space to schedule a new slot
        if (appointment[i].patientNumber < 1)
        {
            slotAvailability = 1;
        }
    }
    return i; //returning the index of the slot available
}

//functon to see if the appointment is valid or not
int appointmentValidity(int patientNumber, struct Date date, struct Appointment* appointment, int max)
{
    int i, validity = 0;
    for (i = 0; i < max && validity == 0; i++)
    {
        if ((appointment[i].patientNumber == patientNumber) && (appointment[i].date.day == date.day) && (appointment[i].date.month == date.month) && (appointment[i].date.year == date.year))
        {
            validity = 1;

        }

    }
    return (i - 1);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data) {
    int i, j;

    // Sorting the data in the array
    sortAppointments(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}




// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int maxMonthDay = 31;
    int i, j;
    struct Date date;

    // Taking the year as input
    printf("Year        : ");
    date.year = inputIntPositive();

    // Taking the month as input
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    // Taking the day as input
    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11) {
        maxMonthDay = 30;
    }
    if (date.month == 2) {
        maxMonthDay = 28;
    }
    if (date.year % 4 == 0 && date.month == 2) {
        maxMonthDay = 29;
    }

    printf("%d)  : ", maxMonthDay);
    date.day = inputIntRange(1, maxMonthDay);
    printf("\n");

    // Sorting the data is the array
    sortAppointments(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");

}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients)
{
    struct Date date;
    struct Time time;

    int maxMonthDay = 31, slotAvailability = 1, patientNum, returnValue;
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    returnValue = findPatientIndexByPatientNum(patientNum, patient, maxPatients);
    if (returnValue >= 0)
    {
        while (slotAvailability)
        {
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
            date.month = inputIntRange(1, 12);
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11)
            {
                maxMonthDay = 30;
            }
            if (date.month == 2)
            {
                maxMonthDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2)
            {
                maxMonthDay = 29;
            }
            printf("%d)  : ", maxMonthDay);
            date.day = inputIntRange(1, maxMonthDay);
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);
            if (timeSlot(date, time, appointment, maxAppointments))
            {
                printf("\n");
                printf("ERROR: Appointment timeslot is not available!\n\n");
            }
            else
            {
                while ((time.hour<MIN_HOUR || time.hour>MAX_HOUR) || (time.hour == MAX_HOUR && time.min > 0) || (time.min % MIN_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %d minute intervals.\n\n", MIN_HOUR, MAX_HOUR, MIN_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);

                    if (timeSlot(date, time, appointment, maxAppointments))
                    {
                        printf("\n");
                        printf("ERROR: Appointment timeslot is not available!\n\n");
                    }
                    else
                    {
                        while ((time.hour<MIN_HOUR || time.hour>MAX_HOUR) || (time.hour == MAX_HOUR && time.min > 0) || (time.min % MIN_INTERVAL != 0))
                        {
                            printf("ERROR: Time must be between %02d:00 and %02d:00 in %d minute intervals.\n\n", MIN_HOUR, MAX_HOUR, MIN_INTERVAL);
                            printf("Hour (0-23)  : ");
                            time.hour = inputIntRange(0, 23);
                            printf("Minute (0-59): ");
                            time.min = inputIntRange(0, 59);

                        }
                        slotAvailability = 0; //changing the value of availability when slot is not available

                    }

                }
                returnValue = nextSlot(appointment, maxAppointments); //to find the index of the next slot available
                appointment[returnValue].date = date;
                appointment[returnValue].time = time;
                appointment[returnValue].patientNumber = patientNum;
                printf("\n*** Appointment scheduled! ***\n\n");
            }
        }
    }
    else
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");

    }
    return;
}





// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patient, int maxPatients) {
    struct Date date;
    int returnValue, patientNumber, maxMonthDay = 0, appointmentIndex;


    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    returnValue = findPatientIndexByPatientNum(patientNumber, patient, maxPatients);

    if (returnValue >= 0) {

        printf("Year        : ");
        date.year = inputIntPositive();


        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11) {
            maxMonthDay = 30;
        }
        if (date.month == 2) {
            maxMonthDay = 28;
        }
        if (date.year % 4 == 0 && date.month == 2) {
            maxMonthDay = 29;
        }
        printf("%d)  : ", maxMonthDay);
        date.day = inputIntRange(1, maxMonthDay);

        appointmentIndex = appointmentValidity(patientNumber, date, appointment, maxAppointments);

        if (appointmentIndex >= 0) {
            printf("\n");

            displayPatientData(&patient[returnValue], FORMATFORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y') {
                appointment[appointmentIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum, recordExist;
    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    recordExist = findPatientIndexByPatientNum(patientNum, patient, max); //check if the return value is -1 or 1
    printf("\n");
    if (recordExist == -1)
    {
        printf("*** No records found ***\n\n");
    }
    else
    {
        printf("Name  : %s\n", patient[recordExist].name);
        printf("Number: %05d\n", patient[recordExist].patientNumber);

        printf("Phone : ");
        displayFormattedPhone(patient[recordExist].phone.number);
        printf(" (%s)", patient[recordExist].phone.description);
        printf("\n\n");

    }

}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, matchCount = 0;
    char patientPhoneNum[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    scanf("%s", patientPhoneNum);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, patientPhoneNum) == 0) //checking if entered and the phone number of the particular record is same
        {
            printf("%05d %-15s ", patient[i].patientNumber,
                patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            matchCount++;

        }
    }
    if (matchCount == 0)
    {
        printf("\n*** No records found ***\n");
    }
    printf("\n");

}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxPatientNum = patient[0].patientNumber, nextPatientNum;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxPatientNum) //finding the largest patient number
        {
            maxPatientNum = patient[i].patientNumber;
        }
    }
    nextPatientNum = maxPatientNum + 1; //storing the next patient number
    return nextPatientNum;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber) //checking if the patient No stored in the record is same as that of enetered
        {
            return i;
        }
    }
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{


    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&(patient->phone)); //sending the address of phone data member through the pointer

}



// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int contactChoice;
    char phoneNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    contactChoice = inputIntRange(1, 4);
    putchar('\n');
    switch (contactChoice)
    {
    case 1:
        // Storing the description in the struct
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(phoneNumber, 10, 10);
        strcpy(phone->number, phoneNumber);
        putchar('\n');

        break;

    case 2:
        // Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(phoneNumber, 10, 10);
        strcpy(phone->number, phoneNumber);
        putchar('\n');

        break;

    case 3:
        // Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(phoneNumber, 10, 10);
        strcpy(phone->number, phoneNumber);
        putchar('\n');

        break;

    case 4:
        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;
    }
}



//Importing data about patients.
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* file = fopen(datafile, "r"); //Opening the file in read mode
    if (file != NULL) //checking if the address is not null
    {
        while (fscanf(file, " %d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF)
        {
            i++;
            if (i >= max)
            {
                break;
            }
        }

        fclose(file); //closing the file
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return i;
}

//Importing data about Appointments
int importAppointments(const char* datafile, struct Appointment appointments[], int max)
{
    int i = 0, recordCount = 0;
    FILE* file = fopen(datafile, "r"); //opening the file in read mode
    if (file != NULL) //checking if the address is not null
    {
        for (i = 0; i < max && !feof(file); i++)
        {
            fscanf(file, "%d,%d,%d,%d,%d,%d", &appointments[i].patientNumber, &appointments[i].date.year, &appointments[i].date.month, &appointments[i].date.day, &appointments[i].time.hour, &appointments[i].time.min);

            if (!feof(file)) //checking if the file successfully formatted input
            {
                recordCount++;;
            }

        }

        fclose(file); //closing the file
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return recordCount;

}