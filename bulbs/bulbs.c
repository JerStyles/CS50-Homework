#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Prompt user for input
    string text = get_string("MESSAGE: ");

    // Covert letters to numbers
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        for (int j = 0, p = BITS_IN_BYTE - 1, t = text[i]; p >= 0; j++, p--)
        {
            int e = pow(2, p);
            // check the biggest binary bit
            if (t < e)
            {
                print_bulb(0);
            }
            else
            {
                print_bulb(1);
                // assign remainder as the new value
                t %= e;
            }
        }
        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
