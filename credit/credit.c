#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validate_number (long n);
void check_issuer (long n);

int main(void)
{
    long n = get_long("Number: ");

    // validate initial input AND validate credit card numbers
    if ((n > 0 && n < 5.6 * pow(10,15)) && validate_number(n) == 0)
    {
        check_issuer(n);
    }
    else
    {
        printf("INVALID\n");
    }
}

int validate_number (long n)
{
    int digit = 0, subTotal = 0, grandTotal = 0;

    for (int i = 0; i < 16; i++)
    {
        // get digit or assign new value
        digit = n % 10;
        n = ( n - digit) / 10;

        // decide if to continue the loop
        if (digit <= 0 && n <= 0)
        {
            break;
        }
        // assign new n for next loop
        else
        {
            // get subTotal for odds and evens
            if (i % 2 == 1){
                subTotal = digit;
            }
            else
            {
                subTotal = digit * 2;
            }

            // get granTotal by adding up this and previous loops
            grandTotal += subTotal;
        }
    }
    // validate grandTotal
    if (grandTotal % 10 == 0 && grandTotal > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void check_issuer(long n)
{
    while (n >= 10)
    {
        n /= 10;
    }

    int firstDigit = n;
    if (firstDigit == 3)
    {
        printf("AMEX\n");
    }
    else if (firstDigit == 4)
    {
        printf("VISA\n");
    }
    else if (firstDigit == 5)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("ISSUER NOT RECOGNIZED\n");
    }
}