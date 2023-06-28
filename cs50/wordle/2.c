#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int score = 0;
    string guess = "derht";
    string choice = "karty";
    int status[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tolower(guess[i]) == tolower(choice[j]))
            {
                if (i == j)
                {
                    score = 2;
                    break;
                }
                else
                {
                    score = 1;
                }
                break;
            }
            else
            {
                score = 0;
            }
        }
        status[i] = score;
        printf("%i ", score);
    }
    int total_score = 0;
    for (int i = 0; i < 5; i++)
    {
        total_score += status[i];
    }
    printf("\nTotal Score: %i\n", total_score);
    return total_score;
}
