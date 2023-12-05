#include <iostream>
#include <cctype>
#include <cstring>

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

PASSWORD_ERROR checkPassword(const std::string& password);

int main()
{
    string password;
    cout << "Enter your password: ";
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

PASSWORD_ERROR checkPassword(const std::string& password)
{
    // Check if the password is at least 8 characters long
    if (password.length() < 8)
    {
        return PASSWORD_ERROR_TOO_SHORT;
    }

    // Check if the password contains at least one uppercase letter,
    // one lowercase letter, and one digit 
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;

    for(char ch : password)
    {
        if (isupper(ch))
        {
            hasUppercase = true;
        }
        else if(islower(ch))
        {
            hasLowercase = true;
        }
        else if (isdigit(ch))
        {
            hasDigit = true;
        }
    }

    if (!hasUppercase)
    {
        return PASSWORD_ERROR_NO_UPPERCASE_LETTER;
    }
    
    if (!hasLowercase)
    {
        return PASSWORD_ERROR_NO_LOWERCASE_LETTER;
    }

    if (!hasDigit)
    {
        return PASSWORD_ERROR_NO_NUMBER;
    }

    // Check if the password contains certain words
    const char *forbiddenWords[] = {"password", "secret", "summer", "winter"};

    for (const char *forbiddenWord : forbiddenWords)
    {
        if (password.find(forbiddenWord) != string::npos)
        {
            return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
        }
    }

    return PASSWORD_ERROR_OK;
}
