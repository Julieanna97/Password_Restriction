/**
 * @file main.cpp
 * @author Julie Anne (julie.cantillep@studerande.movant.se)
 * @brief A program that demonstrates password verifier with set limit
 * of characters and symbols
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cctype>
#include <cstring>
#include "isValidPassword.h"

using namespace std;

typedef enum
{
    PASSWORD_ERROR_OK,
    PASSWORD_ERROR_TOO_SHORT,   // Minimum 8 characters
    PASSWORD_ERROR_NO_UPPERCASE_LETTER, // Minimum 1 upper case 'A'
    PASSWORD_ERROR_NO_LOWERCASE_LETTER, // Minimum 1 lower case 'a'
    PASSWORD_ERROR_NO_NUMBER,    // At least 1 number '1'
    PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS   // Can't contain words like
                                                // password, secret, summer, winter
} PASSWORD_ERROR;

PASSWORD_ERROR checkPassword(const char *password);

int main()
{
    const char *password[255];
    cout <<"Enter your password: ";
    cin >> password;

    PASSWORD_ERROR result = checkPassword(password);

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

    return 0;

}

PASSWORD_ERROR checkPassword(const char *password)
{



}