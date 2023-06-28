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

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
//The formula to calculate the average number of letters per 100 words in the text
    float L = (letters / words) * 100;
//The formula to calculate the average number of sent. per 100 words in the text
    float S = (sentences / words) * 100;

    printf("Ltrs = %f, Wrds = %f Stss = %f \n", letters, words, sentences);
    printf("L = %f, S = %f \n", L, S);
    float Grade = 0.0588 * L - 0.296 * S - 15.8;
    printf("Grade not round float = %f\n", Grade);
    float gradef = round(0.0588 * L - 0.296 * S - 15.8);
    printf("Grade round float = %f\n", gradef);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    printf("Grade round int = %i\n", grade);
// Conditions
    if (grade < 1)
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

// Count letters
int count_letters(string text)
{
    float letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}

// Count words
int count_words(string text)
{
    float words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

// Count sentences
int count_sentences(string text)
{
    string characters = ".!?";
    float sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < strlen(characters); j++)
        {
            if (text[i] == characters[j])
            {
                sentences++;
                break;
            }
        }
    }
    return sentences;
}