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

    // decide total numbers of rows
    for (int row = 0; row < n; row++)
    {
        // decide total numbers of columns
        for (int col = 0; col < n * 2 + 2 ;col++)
        {
            // control space at the left and right.
            if (col + row < n - 1 || col - row >= n + 3)
            {
                printf(" ");
            }
            // control space at the middle.
            else if (col == n || col == n + 1)
            {
                printf(" ");
            }
            // fill in the rest with #hashtags
            else
            {
                printf("#");
            }
        }
        printf("\n");

    }

}