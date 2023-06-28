#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool only_letters(string s);
bool only_one(string s);
char subst(char c, string s);


int main(int argc, string argv[])//1 Get key by means of CLI
{
    // Validate key:
    if (argc != 2)// checks whether the program was run with the only command-line argument (and programm name as default)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1; //if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    if (strlen(argv[1]) != 26)// Check key length
    {
        printf("Key must contain 26 characters.\n");
        return 1; //if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    if (only_letters(argv[1])) //takes 2nd word as an argument and returns true if that string contains only letters
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;//if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    if (only_one(argv[1])) //takes 2nd word as an argument and returns true if that string contains repeated letters (case-insensitive)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;//if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    string plaintext = get_string("plaintext: ");// prompt for text
    printf("ciphertext: ");//Print ciphertext

    for (int i = 0; i < strlen(plaintext); i++)//one by one,
    {
        char c = plaintext[i];//take chars fm txt and
        char c_mod = subst(c, argv[1]);//shift and print them, but if they are letters only
    }
    printf("\n");
}

// shiftig
char subst(char c, string s)
{
    char c_mod = c;
    string letter_map_up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string letter_map_lo = "abcdefghijklmnopqrstuvwxyz";
    if (isalpha(c)) //check if it is a letter, than:
    {
        if (isupper(c))//if upper, than than this mapping
        {
            for (int j = 0; j < 26; j++)
            {
                if (c == letter_map_up[j])
                {
                    c_mod = toupper(s[j]);
                    break;
                }
            }
        }
        else
        {
            for (int k = 0; k < 26; k++)//if lower, than this mapping
            {
                if (c == letter_map_lo[k])
                {
                    c_mod = tolower(s[k]);
                    break;
                }
            }
        }
        printf("%c", c_mod);
    }
    else//If the char is not a letter, the function should instead return the same char unchanged
    {
        printf("%c", c);//c_mod = c;//  Leave non-alphabetic characters as-is.
    }

    return 0;
}

// "if letters" checking
bool only_letters(string s) // input here our 2nd sub-array, i.e. (argv[1])
{
    for (int i = 0; i < strlen(s); i++) // there check all chars in it, one by one
    {
        if (!isalpha(s[i]))
        {
            return true;//if it digit than true
        }
    }
    return 0;
}

bool only_one(string s) // input here our 2nd sub-array, i.e. (argv[1])
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++) // here check all chars in array, one by one
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (toupper(s[i]) == toupper(s[j]))//compare each element of the array with every other element in the array.
            {
                count++;
            }
        }
    }
    if (count != 0)
    {
        return true;//if string contains repeated letters (case-insensitive) than true
    }
    return 0;
}
