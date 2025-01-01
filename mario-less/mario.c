#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height? ");
    }
    while (n < 1 || n > 8);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n ;col++)
        {
            if (col + row < n - 1 )
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");

    }

}