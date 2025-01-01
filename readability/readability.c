#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: ");
    int n = strlen(text);
    int letters = 0, spaces = 0, words = 0, sentences = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            spaces++;
        }
        else if (text[i] == '!' || text[i] ==  '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    if (spaces > 0)
    {
        words = spaces + 1;
    }

    // count grades
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}