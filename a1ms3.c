#include <stdio.h>

#include "clinic.h"  // Including the header file that contains struct and function declarations

#define MAX_PETS 20
#define MAX_APPOINTMENTS 50

int main(void)
{
    // Declare arrays of structs for patients and appointments, and create a struct to hold clinic data
    struct Patient pets[MAX_PETS] = { {0} };
    struct Appointment appoints[MAX_APPOINTMENTS] = { {0} };
    struct ClinicData data = { pets, MAX_PETS, appoints, MAX_APPOINTMENTS };

    // Import patient and appointment data from files
    int patientCount = importPatients("patientData.txt", pets, MAX_PETS);
    int appointmentCount = importAppointments("appointmentData.txt", appoints, MAX_APPOINTMENTS);

    // Print the number of imported patient and appointment records
    printf("Imported %d patient records...\n", patientCount);
    printf("Imported %d appointment records...\n\n", appointmentCount);

    // Call the main menu function to start the program
    menuMain(&data);

    // Return 0 to indicate successful program execution
    return 0;
}
