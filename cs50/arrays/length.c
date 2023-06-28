#include <cs50.h>
#include <stdio.h>
#include <string.h> //this is for string length!!!
int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)tt alwais
    // present in String type arrays!!!
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);

//2nd variant:

    // Prompt for user's name
    int length = strlen(name);
    printf("%i\n", length);
}