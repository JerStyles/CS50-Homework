// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int start, int end);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, 0, n - 1));
}

// TODO: return the max value
int max(int array[], int start, int end)
{

    if (start == end)
    {
        return array[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int max1 = max(array, start, mid);
        int max2 = max(array, mid+ 1, end);

        return (max1 > max2)? max1:max2;
    }

}
