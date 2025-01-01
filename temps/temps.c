#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void mergeSort(int low, int high);
void merge(int low, int mid, int high);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;


    mergeSort(0, NUM_CITIES - 1);

    printf("\nAverage July Temperatures by City (Descending Order)\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    avg_temp left[leftSize];
    avg_temp right[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        left[i] = temps[low + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        right[j] = temps[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize)
    {
        if (left[i].temp >= right[j].temp)
        {
            temps[k] = left[i];
            i++;
        }
        else
        {
            temps[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        temps[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        temps[k] = right[j];
        j++;
        k++;
    }
}
