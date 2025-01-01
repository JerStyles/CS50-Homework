// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //iterate through characters
    int total = 0;
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]))
        {
            total += 1;
            break;
        }
    }

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isupper(password[i]))
        {
            total += 1;
            break;
        }
    }

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isdigit(password[i]))
        {
            total += 1;
            break;
        }
    }

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (ispunct(password[i]))
        {
            total += 1;
            break;
        }
    }

    if (total >= 4)
    {
       return true;
    }
    else
    {
        return false;
    }
}
