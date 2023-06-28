#include <stdio.h>

int main() {
    int word_5678 = 5;
    if ((word_5678 < 5) || (word_5678 > 8))
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    // rest of the code
    return 0;
}