#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string argv);
char rotate (char t, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Convert argv[1] from a `string` to an `int`
        int key = atoi(argv[1]);

        // Prompt user for plaintext
        string text = get_string("plaintext: ");

        // For each character in the plaintext:
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            text[i] = rotate (text[i], key);
        }

        printf("ciphertext: %s\n", text);
        return 0;

    }
}

bool only_digits(string argv)
{
    for (int i = 0, n = strlen(argv); i < n; i++)
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate (char t, int key)
{
    if  islower(t)
    {
        return (t - 'a' + key)% 26 + 'a';
    }
    else if isupper(t)
    {
        return (t - 'A' + key)% 26 + 'A';
    }

    return t;
}