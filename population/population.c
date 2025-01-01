#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    int population;
    do
    {
        population = get_int("End Size: ");
    }
    while (population < n);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    if (n == population)
        {
            printf("Years: %i\n", years);
            return 0;
        }

    do
    {
        n = n + (int) (n / 3) - (int) (n / 4);
        years += 1;
    }
    while (n < population);

    // TODO: Print number of years
    printf("Years: %i\n", years);
    return 0;
}
