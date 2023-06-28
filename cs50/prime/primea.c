#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    int j;
    int fig;
    for (int i = min; i<= max; i++)
    {
        printf("%i\n", i);
        if (2 < i < (max - 1))
        {
            fig = i / 2;
            printf("%i\n", fig);
        }
    }
}