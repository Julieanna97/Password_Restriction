#include "password.h"
#include <cctype>

using namespace std;

PASSWORD_ERROR checkPassword(const char *password)
{
    PASSWORD_ERROR return_value = PASSWORD_ERROR_OK;

    // Check if the password is at least 8 characters long
    if (strlen(password) < 8)
    {
        return_value = PASSWORD_ERROR_TOO_SHORT;
    }

    // Check if the password contains at least one uppercase letter,
    // one lowercase letter, and one digit
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for(const char *ch = password; *ch != '\0'; ++ch)
    {
        if (isupper(*ch))
        {
            hasUpperCase = true;
        }
        else if (islower(*ch))
        {
            hasLowerCase = true;
        }
        else if (isdigit(*ch))
        {
            hasDigit = true;
        }

    }

    if (!hasUpperCase)
    {
        return_value = PASSWORD_ERROR_NO_UPPERCASE_LETTER;
    }
    else if (!hasLowerCase)
    {
        return_value = PASSWORD_ERROR_NO_LOWERCASE_LETTER;
    }
    else if (!hasDigit)
    {
        return_value = PASSWORD_ERROR_NO_NUMBER;
    }
    
    // Check if the password contains certain words
    const char *forbiddenWords[] = {"password", "secret", "summer", "winter"};

    for (const char *forbiddenWord : forbiddenWords)
    {
        if (strstr(password, forbiddenWord) != nullptr)
        {
            return_value = PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
        }
    }

    return return_value;

}