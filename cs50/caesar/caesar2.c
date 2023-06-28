#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)// checks whether the program was run with the only command-line argument (and programm name as default)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1; //if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    if (only_digits(argv[1]) == false) //takes a string as an argument and returns true if that string contains only digits
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;//if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    int key = atoi(argv[1]); // Convert the key from a string to an integer - do not foget include stdlib.h!!!
    //printf("key int: %d\n", key);

    string plaintext = get_string("plaintext: ");// prompt for text

    printf("ciphertext: ");


    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        rotate(c, key);
    }
    printf("\n");
}

bool only_digits(string s) // input here our 2nd sub-array, i.e. (argv[1])
{
    for (int i = 0; i < strlen(s); i++) // there check all chars in it, one by one
    {
        if (isdigit(s[i]))
        {
            return true;//if it digit than true
        }
    }
    return false;
}

char rotate(char c, int key)
{
    if (isalpha(c)) //check if it is a letter, than:
    {
        char basis; //or: char basis = isupper(c) ? 'A' : 'a';
        if (isupper(c))
        {
        basis = 'A'; //if upper than count fm 'A' (65)
        } else {
        basis = 'a'; //if lower than count fm 'a' (97)
        }
        //printf("%c. is it upper:(%c)?, ", c, basis);
        int shifting = c - basis;//shifting fm A(a)
        //printf("shifting fm A(a) - %i, ", shifting);
        int rotated_shifting = (shifting + key) % 26;//shifting + key (int)
        //printf("shifting + key (int)- %i,", rotated_shifting);
        char rotated_c = basis + rotated_shifting; //basis + shifting + key (char)
        printf("%c", rotated_c);
    }
    else//If the char is not a letter, the function should instead return the same char unchanged
    {
        printf("%c", c);
    }
    return 0;
}