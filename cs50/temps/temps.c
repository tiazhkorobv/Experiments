// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

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

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Bubble sort algorithm
    for (int i = 0; i < NUM_CITIES - 1; i++)//compare each element to the elements that come after it
    {
        for (int j = 0; j < NUM_CITIES - i - 1; j++)//compare each pair of adjacent elements until we get to the end of the array
        {
            if (temps[j].temp < temps[j + 1].temp)//compare the temp field of the current element temps[j] to the temp field of the next element temps[j + 1]
            {// Swap the elements
                avg_temp temp = temps[j];//create a temporary avg_temp struct temp and copy the contents of temps[j] into it.
                temps[j] = temps[j + 1];//copy the contents of temps[j + 1] into temps[j], effectively swapping the two elements/
                temps[j + 1] = temp;//copy the contents of temp into temps[j + 1], completing the swap.
            }
        }
    }
}
/**we chose to use the bubble sort algorithm because it's a simple sorting algorithm that's easy to understand and implement.
  It's not the most efficient sorting algorithm, but for a small array like this one with only 10 elements, the performance
  difference between bubble sort and a more efficient sorting algorithm would be negligible.

Another reason we might choose bubble sort is that it's a stable sorting algorithm,
 which means that if two elements in the array have the same value, their relative
 order will be preserved after sorting. In this case, if two cities have the same
 temperature, we'd want to preserve their order based on the order they were added
  to the array.

If we were working with a much larger array, we might consider using a more
efficient sorting algorithm like quicksort, mergesort, or heapsort, which have
 better worst-case time complexity than bubble sort. However, for small arrays
 or arrays that are already partially sorted, bubble sort can be a reasonable choice./