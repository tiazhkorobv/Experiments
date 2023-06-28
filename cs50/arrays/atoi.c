#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(void);

int main(void)
{
     string input = get_string("Enter a positive integer: ");
     int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    printf("l-%i\n", n);
    //Convert string to int
    printf("%i\n", convert(input));

    //input[strlen(input) + 1] = '\0';
    int last_index = strlen(input);
    printf("%i\n", last_index);
    printf("%s\n", input);
    printf("%c\n", input[0]);// Base case: the string contains only one character
    printf("%c\n", input[1]);// if (last_index == 0)
    printf("%c\n", input[2]);// {
    printf("%c\n", input[3]);//     return input[last_index] ;
    // }
    // else
    // {
    //     );
    // }
    //return last_index;
}