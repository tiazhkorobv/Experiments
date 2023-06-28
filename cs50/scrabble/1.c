#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    // Keep truck scores
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    char word[] = "Abcd";
    // Compute score for each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
            printf("%i ",score);
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
            printf("%i ",score);
        }
    }printf("\n");
    return score;
}