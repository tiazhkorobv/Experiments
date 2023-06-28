#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string text = get_string("Message: ");// Get text n make input string
    int length = strlen(text); // get length
    int ascii[length]; // make array for ASCII-values

    for (int i = 0; i < length; i++) // convert text array into array of ASCII-values
    {
        if (text[i] == '\n') // skeep NewLine (when hit Eneter)
        {
            continue;
        }
        ascii[i] = text[i];
    }

    for (int i = 0; i < length; i++) // convert ascii values from array into binary codes consicventualy
    {
        if (text[i] == '\n') // skeep NewLine (when hit Eneter)
        {
            continue;
        }
        int ascii_volume = ascii[i]; // get each ASCII-value
        int binary[BITS_IN_BYTE] = {0}; // make 8-bit array filled by zeros

        int j = 0; // index in 8-bit array
        while (ascii_volume > 0) // do loop until the imposs division by 0
        {
            int remainder = ascii_volume % 2; // get reminder of division by 2
            binary[j] = remainder; // save into 8-bit array
            j++; // increese array index
            ascii_volume = ascii_volume / 2; // divide by 2, then go to next iteration
        }

        // for (int k = 7; k >= 0; k--) // output 8-bit array in vice-versa order
        // {
        //     printf("%d", binary[k]);
        // }
        // printf("\n"); // New line between every binary

        for (int l = 7; l >= 0; l--)// output 8-bit array in vice-versa order
        print_bulb(binary[l]);
        // {
        //     if (binary[l] == 0)
        //     {
        //         printf("\U000026AB");// Dark emoji
        //     }
        //     else if (binary[l] == 1)
        //     {
        //         printf("\U0001F7E1");// Light emoji
        //     }
        // }
        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
