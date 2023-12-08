#include "password.h"
#include <cstring>
#include <cctype>

using namespace std;

PASSWORD_ERROR checkPassword(const char *password)
{
    // Check if the password is at least 8 characters long
    if (strlen(password) < 8)
    {
        return PASSWORD_ERROR_TOO_SHORT;
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
        return PASSWORD_ERROR_NO_UPPERCASE_LETTER;
    }
    else if (!hasLowerCase)
    {
        return PASSWORD_ERROR_NO_LOWERCASE_LETTER;
    }
    else if (!hasDigit)
    {
        return PASSWORD_ERROR_NO_NUMBER;
    }
    
    // Check if the password contains certain words
    const char *forbiddenWords[] = {"password", "secret", "summer", "winter"};

    for (const char *forbiddenWord : forbiddenWords)
    {
        if (strstr(password, forbiddenWord) != nullptr)
        {
            return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
        }
    }

    return PASSWORD_ERROR_OK;

}


/*
PASSWORD_ERROR checkPassword(const char *password)
{
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;

    for (size_t i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
            uppercaseCount++;
        if (islower(password[i]))
            lowercaseCount++;
        if (isdigit(password[i]))
            digitCount++;
    }
    
    if (uppercaseCount == 0)
    {
        return PASSWORD_ERROR_NO_UPPERCASE_LETTER;
    }
    if (lowercaseCount == 0)
    {
        return PASSWORD_ERROR_NO_LOWERCASE_LETTER;
    }
    if (digitCount == 0)
    {
        return PASSWORD_ERROR_NO_NUMBER;
    }

    if (strstr(password, "password") != nullptr)
    {
        return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    }
    if (strstr(password, "secret") != nullptr)
    {
        return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    }
    if (strstr(password, "summer") != nullptr)
    {
        return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    }
    if (strstr(password, "winter") != nullptr)
    {
        return PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS;
    }

    if (strlen(password) < 8)
    {
        return PASSWORD_ERROR_TOO_SHORT;
    }

    return PASSWORD_ERROR_OK;

}
*/