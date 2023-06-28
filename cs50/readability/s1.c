#include <cs50.h>
#include <stdio.h>

#define _GNU_SOURCE
#include <string.h>

int main(void)
{
    string haystack = "FOO BAR BAR BAZ";
    string needle = "O";
    int score = 0;
    string match = strstr (haystack, needle);
    for (int i = 0, len = strlen(haystack); i < len; i++)
    {
        if (match)
        {
        score ++;
        printf("ssa %s\n", match);
        }
    }
    printf("words %i\n", score);
}

   char str[100];
   char ch;
   int count = 0, i;

   printf("Введите строку: ");
   gets(str);

   for (i = 0; str[i] != '\0'; i++) {
      if (str[i] == ch)
         count++;
   }

   printf("Количество вхождений символа %c в строку %s равно %d\n", ch, str, count);

   return 0;
}
