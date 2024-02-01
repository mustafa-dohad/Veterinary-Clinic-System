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

#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for the user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Guarantees that a valid integer is entered
int inputInt(void);

// Guarantees that a valid positive integer is entered (greater than zero)
int inputIntPositive(void);

// Guarantees that the value entered is between the permitted range
int inputIntRange(int lowerBound, int upperBound);

// Guarantees that the character entered is present in the string
char inputCharOption(const char str[]);

// Obtains user input for a string
void inputCString(char *str, int minChar, int maxChar);

// Obtains user input for a number
void inputCStringNumbers(char *str, int minChar, int maxChar);

// Displays an array of 10 digits of a phone number
void displayFormattedPhone(const char *str);

#endif // !CORE_H
