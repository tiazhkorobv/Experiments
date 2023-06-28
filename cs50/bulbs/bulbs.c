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
        ascii[i] = text[i]; // chars => int will be automaticly
    }

    for (int i = 0; i < length; i++) // convert ascii values from array into binary codes consequentualy
    {
        int ascii_volume = ascii[i]; // get each ASCII-value
        int binary[BITS_IN_BYTE] = {0}; // make 8-bit array filled by zeros
        int j = 0; // index in 8-bit array
        while (ascii_volume > 0) // do loop until the imposs division by 0
        {
            int remainder = ascii_volume % 2; // get reminder of division by 2
            binary[j] = remainder; // save remainder into 8-bit array
            j++; // increese array index
            ascii_volume = ascii_volume / 2; // divide by 2, then go to next iteration
        }

        for (int l = 7; l >= 0; l--)// output 8-bit array in vice-versa order
        {
            print_bulb(binary[l]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        printf("\U000026AB");// Dark emoji
    }
    else if (bit == 1)
    {
        printf("\U0001F7E1");// Light emoji
    }
}