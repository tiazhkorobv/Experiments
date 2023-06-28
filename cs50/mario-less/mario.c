#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get size
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    //return n;
    //printf("Stored: %i\n", n);

    // Print hill
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            printf(" ");
        }
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }
        printf("\n");
    }
}