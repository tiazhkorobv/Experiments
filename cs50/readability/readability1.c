#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
// Get text
    string text = get_string("Text: ");
    //printf("%s\n", text);
    double letters = count_letters(text); // not float!!!
    double words = count_words(text);// not float!!!
    double sentences = count_sentences(text);// not float!!!
    //printf("L = %.2f, S = %.2f \n", letters, words);
    double L = (letters / words) * 100;   //The formula to calculate the average number of letters per 100 words in the text is: (L/W) x 100
    double S = (sentences / words) * 100;   //The formula to calculate the average number of letters per 100 words in the text is: (L/W) x 100;
    //printf("L = %.2f, S = %.2f \n", L, S);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

        if(grade < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (grade <= 16)
        {
            printf("Grade %d\n", grade);
        }
        else
        {
            printf("Grade 16+\n");
        }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    //printf("%i letters \n", letters);
    return letters;
}

int count_words(string text)
{
    int character = ' ';
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
        {
        if (text[i] == character)
    // Or this way
    // for (int i = 0, len = strlen(text); i < len; i++)
    //      {
    //         if (isspace(text[i]))
            {
                words++;
            }
        }
    //printf("%i words \n", words);
    return words;
}

int count_sentences(string text)
{
    char characters[] = {'.', '!', '?'}; ///Error is here!!!  Must be  - ".?!"
    int sentences = 0;
    // for (int i = 0; text[i] != '\0'; i++)
    //     {
  for (int i = 0; i < strlen(text); i++)
        {
           for (int j = 0; j < strlen(characters); j++)
          //for (int j = 0; characters [j] != '\0'; j++) do not work here!!!
               {
                    if (text[i] == characters[j])
                    {
                          sentences++;
                          break;
                    }
                }

         }
    //printf("%i sentences \n", sentences);
    return sentences;
}