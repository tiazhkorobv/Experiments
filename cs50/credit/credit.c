#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Prompts the user for a credit card number
    long no = get_long("Number: ");
    long f_number = no;

// Length of the number:
    char str[16] = "";
    long b = f_number;
    int y = 0;
    while (b >= 10)
    {
        b = b / 10;
        y ++;
    }
// the length will be stored in variable y
    int size = y + 1;
    str[y + 1] = '\0';
// the while loop below will store the digit from the end of str to the the beginning
    while (y >= 0)
    {
        str[y] = f_number % 10 + 48;
        f_number = f_number / 10;
        y--;
    }

// Get 1st digit fm last
    int no1 = no % 10;

// Get 2th digit fm last
    no = no / 10;
    int no2 = no % 10;
    int no2a = no2 * 2 / 10;
    int no2b = no2 * 2 % 10;

// Get 3rd digit fm last
    no = no / 10;
    int no3 = no % 10;

// Get 4th digit fm last
    no = no / 10;
    int no4 = no % 10;
    int no4a = no4 * 2 / 10;
    int no4b = no4 * 2 % 10;

// Get 5th digit fm last
    no = no / 10;
    int no5 = no % 10;

// Get 6th digit fm last
    no = no / 10;
    int no6 = no % 10;
    int no6a = no6 * 2 / 10;
    int no6b = no6 * 2 % 10;

// Get 7th digit fm last
    no = no / 10;
    int no7 = no % 10;

// Get 8th digit fm last
    no = no / 10;
    int no8 = no % 10;
    int no8a = no8 * 2 / 10;
    int no8b = no8 * 2 % 10;


// Get 9th digit fm last
    no = no / 10;
    int no9 = no % 10;

// Get 10th digit fm last
    no = no / 10;
    int no10 = no % 10;
    int no10a = no10 * 2 / 10;
    int no10b = no10 * 2 % 10;

// Get 11th digit fm last
    no = no / 10;
    int no11 = no % 10;

// Get 12th digit fm last
    no = no / 10;
    int no12 = no % 10;
    int no12a = no12 * 2 / 10;
    int no12b = no12 * 2 % 10;

// Get 13th digit fm last
    no = no / 10;
    int no13 = no % 10;

// Get 14th digit fm last
    no = no / 10;
    int no14 = no % 10;
    int no14a = no14 * 2 / 10;
    int no14b = no14 * 2 % 10;

// Get 15th digit fm last
    no = no / 10;
    int no15 = no % 10;

// Get 16th digit fm last
    no = no / 10;
    int no16 = no % 10;
    int no16a = no16 * 2 / 10;
    int no16b = no16 * 2 % 10;

// Multiply every other digit by 2, starting with the number’s second-to-last, add those products’
// digits (and mind tt 14 means 1 and 4!)together
    int sum_even = no2a + no2b + no4a + no4b + no6a + no6b + no8a + no8b + no10a + no10b + no12a + no12b + no14a + no14b + no16a + no16b;

// Add the sum to the sum of the digits that weren’t multiplied by 2
    int sum_odd = no1 + no3 + no5 + no7 + no9 + no11 + no13 + no15;
    int checksum = sum_even + sum_odd;

    char valdty;
// If the total’s last digit is 0 number is valid
    if ((checksum % 10) != 0)
    {
        valdty = 'N';
    }
    else
    {
        valdty = 'Y';
    }

//reports (via printf) whether it is a valid American Express,MasterCard, or Visa card number
    if (size == 16 && valdty == 'Y' && (str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5')))
    {
        printf("MASTERCARD\n");
    }
    else if ((size == 13 || size == 16) && valdty == 'Y' && str[0] == '4')
    {
        printf("VISA\n");
    }
    else if (size == 15 && valdty == 'Y' && (str[0] == '3' && (str[1] == '4' || str[1] == '7')))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
