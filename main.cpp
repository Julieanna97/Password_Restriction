#include <iostream>
#include "password.h"

using namespace std;

int main()
{
    while (true) // Infinite loop
    {
        char input[255];
        cout << "The password tester\nEnter password (type 'exit' to quit): ";
        cin.getline(input, sizeof(input));

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break; // Exit the loop
        }

        PASSWORD_ERROR result = checkPassword(input);

        switch (result)
        {
        case PASSWORD_ERROR_OK:
            cout << "Password is valid." << endl;
            break;
        case PASSWORD_ERROR_TOO_SHORT:
            cout << "Password is too short." << endl;
            break;
        case PASSWORD_ERROR_NO_UPPERCASE_LETTER:
            cout << "Password must contain at least one uppercase letter." << endl;
            break;
        case PASSWORD_ERROR_NO_LOWERCASE_LETTER:
            cout << "Password must contain at least one lowercase letter." << endl;
            break;
        case PASSWORD_ERROR_NO_NUMBER:
            cout << "Password must contain at least one digit." << endl;
            break;
        case PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS:
            cout << "Password can't contain certain words." << endl;
            break;
        }
    }

    return 0;
}
