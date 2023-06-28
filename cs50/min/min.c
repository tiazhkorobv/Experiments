// Practice writing a function to find a min value

#include <cs50.h>
#include <stdio.h>

int min(int array[], int n);

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

    printf("\nThe min value is %i.\n", min(arr, n));
}

// TODO: return the min value
int min(int arr[], int n)
{
    int min_value = arr[0];//Start out with a variable that keeps track of your min value.
                            //start with the first element in the array.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_value)//Loop through the array and reset this min value every time you find a value that’s larger
        {
            min_value = arr[i];
        }
    }
    //printf("\n");
    return min_value;
}