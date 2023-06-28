#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter an integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]) && input[i] != '-')
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int num = 0;
    int last_index = 0, sign = 1;


    if (*input == '\0')// !!!! base case: empty string - is a condition when function will stop
    {
        return 0;
    }
    // skip white space characters
    while (input[last_index + 1] == ' ' || input[last_index] == '\n' || input[last_index] == '\t')
    {
        last_index++;
    }

    // note sign of the number
    if (input[last_index + 1] == '+' || input[last_index] == '-')
    {
    // or
    // if (*input == '+' || *input == '-')
    // {
        if (*input == '-') {
            sign = -1;
        }
        input++;// move input pointer past the sign character
    }

    while (input[last_index + 1] != '\0')// get index of last char in string - step by step
    {
        last_index++;
    }

    char digit = input[last_index];//take chars fm txt
    char basis = '0'; //count fm '0' (48)
    int numeric = digit - basis;//convert last char into numeric value
    input[last_index] = '\0';// remove last char from string by moving the null terminator one position to the left.
    int shortened = convert(input);// recursively compute value of shortened string
    int final = shortened * 10 +
                numeric;// compute final value return this value + 10 times the integer value of the new shortened string.
    // another variant: run till the end of the string is reached, or the current character is non-numeric
    // while (input[last_index] && (input[last_index] >= '0' && input[last_index] <= '9'))
    // {
    //     num = num * 10 + (input[last_index] - '0');
    //     last_index++;
    // }
    return sign * final;
}
//