#include <cs50.h>
#include <ctype.h> //upper case lib!!!
#include <stdio.h>
#include <string.h>

int main(void)
{//The program looks at each character. If the character
//is lowercase, it subtracts the value 32 (accordnly ASCI)from it to convert it to lowercase.
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);printf("%c", toupper(s[i]));
        }
    }//or this way:
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
printf("\n");
// toupper is smart enough to know that if it is passed
// what is already an uppercase letter, it will simply ignore
// it. Therefore, we no longer need our if statement.
// You can simplify this code as follows:
     for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");


}

