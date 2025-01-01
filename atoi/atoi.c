#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototype
int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case: when the string has only one character left
    if (strlen(input) == 1)
    {
        return input[0] - '0';
    }

    // Recursive case: convert the substring without the last character
    int digit = input[strlen(input) - 1] - '0';
    input[strlen(input) - 1] = '\0'; // Remove the last character
    return convert(input) * 10 + digit;
}