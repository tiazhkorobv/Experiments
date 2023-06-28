#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Scores
   int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}//Notice that the number on the right is a floating point value of 3.0,
//such that the calculation is rendered as a floatingpoint value in the end.