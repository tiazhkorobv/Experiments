#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);
string s = argv[1]);

int main(int argc, string argv[])
{
    if (argc != 2)// checks whether the program was run with the only command-line argument (and programm name as default)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1; //if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    if (only_digits(argv[1])) //takes 2nd word as an argument and returns true if that string contains only digits
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;//if is not in condition return printf n exit. If in - return nothing n proceed farther!
    }

    int key = atoi(argv[1]); // Convert the key from a string to an integer - do not foget include stdlib.h!!!

    string plaintext = get_string("plaintext: ");// prompt for text

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)//one by one,
    {
        char c = plaintext[i];//take chars fm txt and
        rotate(c, key);//shift and print them, but if they are letters only
    }
    printf("\n");
}
// "if digit" checking
bool only_digits(string s) // input here our 2nd sub-array, i.e. (argv[1])
{
    for (int i = 0; i < strlen(s); i++) // there check all chars in it, one by one
    {
        if (!isdigit(s[i]))
        {
            return true;//if it digit than true
        }
    }
    return 0;
}

// shiftig
char rotate(char c, int key)
{
    if (isalpha(c)) //check if it is a letter, than:
    {
        char basis;
        if (isupper(c))
        {
            basis = 'A'; //if upper, than count fm 'A' (65)
        }
        else
        {
            basis = 'a'; //if lower, than count fm 'a' (97)
        }
        int shifting = c - basis;//shifting fm A(a)
        int moved_shifting = (shifting + key) % 26;//shifting + key (int). Modul 26 is bcse make loop only within ABC
        char moved_c = basis + moved_shifting; //basis + shifting + key (char)
        printf("%c", moved_c);
    }
    else//If the char is not a letter, the function should instead return the same char unchanged
    {
        printf("%c", c);
    }
    return 0;
}