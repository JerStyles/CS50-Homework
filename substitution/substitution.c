#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int keyLen = 26;
bool validKey(string key);
int main(int argc, string argv[])
{
    // validate input
    if (argc != 2)
    {
        printf("Usage: /substitution key\n");
        return 1;
    }
    else if (!validKey(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;

    }

    // get user input
    string text = get_string("plaintext: ");

    // get character's alphabetic position, map to key according to its postition
    for (int i = 0; i < strlen(text); i++)
    {
        if islower(text[i])
        {
            int j = text[i] - 'a';
            text[i] = tolower(argv[1][j]);
        }
        else if (isupper(text[i]))
        {
            int j = text[i] - 'A';
            text[i] = toupper(argv[1][j]);
        }
    }
    printf("ciphertext: %s\n", text);
}

bool validKey(string key)
{
    if (strlen(key) != keyLen)
    {
        return false;
    }

    bool encountered[26] = {false};

    for (int i = 0; i < keyLen; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        if (encountered[index])
        {
            return false;
        }
        encountered[index] = true;
    }
    return true;
}