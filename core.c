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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        // do nothing!
    }
}

// Wait for the user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Guarantees that a valid integer is entered
int inputInt(void)
{
    char character = 'x'; // initializing the character
    int value;
    do
    {
        if (character != '\n') // checking whether the user has not pressed the enter key
        {
            scanf("%d%c", &value, &character);
            if (character != '\n')
            {
                clearInputBuffer(); // cleaning the input buffer if a valid input is not entered
                printf("Error! Input a whole number: ");
            }
        }
    } while (character != '\n'); // runs until a valid whole number is entered
    return value;
}

// Guarantees that a valid positive integer is entered (greater than zero)
int inputIntPositive(void)
{
    char character = 'x'; // initializing the character
    int value, quitLoop = 0;
    do
    {
        scanf("%d%c", &value, &character);
        if (character != '\n') // checking whether the user has not pressed the enter key
        {
            clearInputBuffer(); // cleaning the input buffer if a valid input is not entered
            printf("Error! Input a whole number: ");
        }
        else
        {
            if (value <= 0)
            {
                printf("ERROR! Value must be > 0: ");
            }
            else if (value > 0)
            {
                quitLoop = 1;
            }
        }
    } while (character != '\n' || quitLoop == 0); // runs until a valid positive integer is entered
    return value;
}

// Guarantees that the value entered is between the permitted range
int inputIntRange(int lowerBound, int upperBound)
{
    char character = 'x'; // initializing the character
    int value, quitLoop = 0;
    do
    {
        scanf("%d%c", &value, &character);
        if (character != '\n') // checking whether the user has not pressed the enter key
        {
            clearInputBuffer(); // cleaning the input buffer if a valid input is not entered
            printf("Error! Input a whole number: ");
        }
        else
        {
            if (value < lowerBound || value > upperBound)
            {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            }
            else if (value >= lowerBound && value <= upperBound)
            {
                quitLoop = 1;
            }
        }
    } while (character != '\n' || quitLoop == 0); // runs until the value entered is within the range
    return value;
}

// Guarantees that the character entered is present in the string
char inputCharOption(const char str[])
{
    char matchingChar;
    int quitLoop = 0, i = 0;
    do
    {
        scanf(" %c", &matchingChar);
        for (i = 0; str[i] != '\0'; i++)
        {
            if (matchingChar == str[i]) // guarantees that the character is present in the string
            {
                quitLoop = 1;
            }
        }
        if (quitLoop == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (quitLoop == 0); // loop runs until the character is found in the string

    clearInputBuffer(); // clears the input buffer after each character entered
    return matchingChar;
}

// Obtains user input for a string
void inputCString(char *CString, int minLen, int maxLen)
{
    int quitLoop = 1;
    char character = 'a';

    while (quitLoop)
    {
        int stringLen = 0;
        // Takes a string as input until it sees a newline character
        while (character != '\n' && stringLen <= maxLen)
        {
            character = getchar();
            CString[stringLen] = character;
            stringLen++;
        }

        // If the string is less than or equal to the maxLen we will just add '\0' to the end to mark the end of the string
        if (character == '\n' && stringLen <= (maxLen + 1))
        {
            stringLen--;
            CString[stringLen] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else
        {
            CString[maxLen] = '\0';
            clearInputBuffer();
        }

        if (minLen == maxLen && stringLen != minLen)
        {
            printf("ERROR: String length must be exactly %d chars: ", minLen);
            character = 'a';
        }
        else if (stringLen < minLen || stringLen > maxLen)
        {
            if (stringLen > maxLen)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLen);
                character = 'a';
            }
            else if (stringLen < minLen)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
                character = 'a';
            }
        }
        else
        {
            quitLoop = 0;
        }
    }
}

void inputCStringNumbers(char *str, int minChar, int maxChar)
{
    int quitLoop = 1;
    char ch = 'x';

    while (quitLoop)
    {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar)
        {
            ch = getchar();
            str[len] = ch;
            len++;
        }

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1))
        {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else
        {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar)
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'x';
        }
        else
        {
            quitLoop = 0;
        }
    }
}

// Displays an array of 10 digits of a phone number
void displayFormattedPhone(const char *phoneNumberString)
{
    int charCount = 0, stringLen = 0;
    // checking whether the address is not null
    if (phoneNumberString != NULL)
    {
        int i = 0;
        stringLen = strlen(phoneNumberString);
        if (stringLen == 10)
        {
            for (i = 0; phoneNumberString[i] != '\0'; i++)
            {
                // checking whether a valid digit is entered
                if (phoneNumberString[i] >= '0' && phoneNumberString[i] <= '9')
                {
                    charCount++;
                }
            }
            // printing the resulting phone number
            if (charCount == 10)
            {
                printf("(");
                for (i = 0; phoneNumberString[i] != '\0'; i++)
                {
                    if (i < 3)
                    {
                        printf("%c", phoneNumberString[i]);
                    }
                }
                printf(")");

                for (i = 0; phoneNumberString[i] != '\0'; i++)
                {
                    if (i >= 3 && i < 6)
                    {
                        printf("%c", phoneNumberString[i]);
                    }
                }
                printf("-");
                for (i = 0; phoneNumberString[i] != '\0'; i++)
                {
                    if (i >= 6 && i < 10)
                    {
                        printf("%c", phoneNumberString[i]);
                    }
                }
            }
            // printing the default output if digit count is not equal to 10
            else
            {
                printf("(___)___-____");
            }
        }
        // printing the default output if string length is not equal to 10
        else
        {
            printf("(___)___-____");
        }
    }
    // printing the default output if address of the string array is not null
    else if (phoneNumberString == NULL)
    {
        printf("(___)___-____");
    }
}
