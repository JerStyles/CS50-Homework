/* Number of weeks taking CS50: 3
Week 0 HW Hours: 3
Week 1 HW Hours: 7
Week 2 HW Hours: 10
Enter T for total hours, A for average hours per week: A
6.7 hours */

# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>


int main (void)
{
    int n = get_int("Number of weeks taking CS50: ");
    int sum = 0;
    char answer;

    for (int i = 0; i < n; i++)
    {
        int hours[n];
        hours[i] = get_int("Week %i HW Hours: ", i);
        sum += hours[i];
    }

    do
    {
        answer = get_char("Enter T for total hours, A for average hours per week: ");
    }
    while (answer != 'T' && answer != 'A');


    if (answer == 'T')
    {
        printf("%i hours\n", sum);
    }
    else if (answer == 'A')
    {
        printf("%.2f hours\n", sum / (float) n);
    }
}