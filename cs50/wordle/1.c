#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
//{
//     char text[] = "hello world";
//     char letter_map[] = "abcdefghijklmnopqrstuvwxyz";
//     char substitute_map[] = "zyxwvutsrqponmlkjihgfedcba";

//     int i, j;
//     for (i = 0; i < strlen(text); i++) {
//         for (j = 0; j < strlen(letter_map); j++) {
//             if (text[i] == letter_map[j]) {
//                 text[i] = substitute_map[j];
//                 break;
//             }
//         }
//     }

//     printf("Substituted text: %s\n", text);

//     return 0;
// }

{
int score = 0;
string guess = "derry";
string choice  = "karty";
int status[5] = {0, 0, 0, 0, 0};
// compare guess to choice and score points as appropriate, storing points in status - TODO #5
    for (int i = 0; i < 5; i++)// iterate over each letter of the guess - here check all chars in array, one by one
    {
        for (int j = i + 1; j < 5; j++)// iterate over each letter of the choice
        {                                       //compare each element of the array with every other element in the array.
            if (tolower(guess[i]) == tolower(choice[j]))// compare the current guess letter to the current choice letter
            {
                score = 2;// if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
                break;
            }
            else //if (tolower(guess[i]) != tolower(choice[j]))// compare the current guess letter to the current choice letter
            {                                  //compare each element of the array with every other element in the array.
                for (int k = 0; k < 5; k++)
                {
                    for (int l = 0; l < 5; l++)
                    {
                        if (tolower(guess[k]) == tolower(choice[l]))
                        {
                            score = 1;// if it's in the word, but not the right spot, score CLOSE point (yellow)
                            break;
                        }
                        else
                        {
                            score = 0;// if it isn't in the word
                        }
                    }
                }
            }
        }
        status[i] = score;// keep track of the total score by adding each individual letter's score from above
        //printf("%i", status[i]);
        //score = score + status[i];
        printf("%i", score);
    }
    printf("\n");
    return score;
}