#include <cs50.h>
#include <stdio.h>

long get_figs(void);
long validity (long f_number);

int main(void)
{
// Prompts the user for a credit card number
long no = get_figs();
long f_number = no;

// Gotten after promt:
printf("Whole: %ld",no);

// Get 1st digit fm last
int no1 = no % 10;
printf("[0] 1 fm_last = %i\n", no1);

// Get 2th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no2 = no % 10;
printf("[1] 2 fm_last = %i  ", no2);
int no2a = no2 * 2 / 10;
printf("2-1 fm last = %i  ", no2a);
int no2b = (no2 * 2) % 10;
printf("2-2 fm last = %i\n", no2b);

// Get 3rd digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no3 = no % 10;
printf("[2] 3 fm_last = %i\n", no3);

// Get 4th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no4 = no % 10;
printf("[3] 4 fm_last = %i  ", no4);
int no4a = no4 * 2 / 10;
printf("4-1 fm last = %i  ", no4a);
int no4b = (no4 * 2) % 10;
printf("4-2 fm last = %i\n", no4b);

// Get 5th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no5 = no % 10;
printf("[4] 5 fm_last = %i\n", no5);

// Get 6th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no6 = no % 10;
printf("[5] 6 fm_last = %i  ", no6);
int no6a = no6 * 2 / 10;
printf("6-1 fm last = %i  ", no6a);
int no6b = (no6 * 2) % 10;
printf("6-2 fm last = %i\n", no6b);

// Get 7th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no7 = no % 10;
printf("[6] 7 fm_last = %i\n", no7);

// Get 8th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no8 = no % 10;
printf("[7] 8 fm_last = %i  ", no8);
int no8a = no8 * 2 / 10;
printf("8-1 fm last = %i  ", no8a);
int no8b = (no8 * 2) % 10;
printf("8-2 fm last = %i\n", no8b);

// Get 9th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no9 = no % 10;
printf("[8] 9 fm_last = %i\n", no9);

// Get 10th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no10 = no % 10;
printf("[9] 10 fm_last = %i  ", no10);
int no10a = no10 * 2 / 10;
printf("10-1 fm last = %i  ", no10a);
int no10b = (no10 * 2) % 10;
printf("10-2 fm last = %i\n", no10b);

// Get 11th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no11 = no % 10;
printf("[10] 11 fm_last = %i\n", no11);

// Get 12th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no12 = no % 10;
printf("[11] 12 fm_last = %i  ", no12);
int no12a = no12 * 2 / 10;
printf("12-1 fm last = %i  ", no12a);
int no12b = (no12 * 2) % 10;
printf("12-2 fm last = %i\n", no12b);

// Get 13th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no13 = no % 10;
printf("[12] 13 fm_last = %i\n", no13);

// Get 14th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no14 = no % 10;
printf("[13] 14 fm_last = %i  ", no14);
int no14a = no14 * 2 / 10;
printf("14-1 fm last = %i  ", no14a);
int no14b = (no14 * 2) % 10;
printf("14-2 fm last = %i\n", no14b);

// Get 15th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no15 = no % 10;
printf("[14] 15 fm_last = %i\n", no15);

// Get 16th digit fm last
no = no / 10;
printf("trkd - %ld", no);
int no16 = no % 10;
printf("[15] 16 fm_last = %i  ", no16);
int no16a = no16 * 2 / 10;
printf("16-1 fm last = %i  ", no16a);
int no16b = (no16 * 2) % 10;
printf("16-2 fm last = %i\n", no16b);

// Multiply every other digit by 2, starting with the number’s second-to-last, add those products’ digits together
int sum_even = no2a + no2b + no4a + no4b + no6a + no6b + no8a + no8b + no10a + no10b + no12a + no12b + no14a + no14b + no16a + no16b;

//int sum_multd = card [1] * 2 + card [3] * 2 + card [5] * 2 + card [7] * 2 + card [9] * 2 + card [11] * 2 + card [13] * 2 + card [15] * 2;
// Add the sum to the sum of the digits that weren’t multiplied by 2
int sum_odd = no1 + no3 + no5 + no7 + no9 + no11 + no13 + no15;
int checksum = sum_even + sum_odd;


// If the total’s last digit is 0 number is valid!
printf("sum_even: %i; sum_odd: %i; checksum: %i\n", sum_even, sum_odd, checksum);

// str will hold the result which is the array
char str[16] = "";
// first we need to see the length of the number f_numbera
long b = f_number;
int y = 0;
while(b > 1)
    {
    b = b/10;
    y ++;
    }
// the length of the number f_numbera will be stored in variable y
// we set the end of the string str as we know the length needed
str[y + 1]= '\0';
// the while loop below will store the digit from the end of str to the the beginning
while(y >= 0)
    {
    str[y] = f_number % 10 + 48;
    f_number = f_number / 10;
    y--;
    }
// only for test
printf("the value of str is \"%s\"\n",str);
// return 0;

// int card [] = {no1, no2, no3, no4, no5, no6, no7, no8, no9, no10, no11, no12, no13, no14, no15, no16};
// //int sum = card [0] + card [2] + card [4] + card [6] + card [8] + card [10] + card [12] + card [14] + sum_multd;
int card [] = {no1, no2, no3, no4, no5, no6, no7, no8, no9, no10, no11, no12, no13, no14, no15, no16};
int size = sizeof(card) / sizeof(card[0]);
int i,j;
for (j = 0; j < size; j++ )
   {
   printf("[%i] = %i; ", j, card[j] );
   }
printf("\n");

for(i = 0; i < size; ++i)
    {
    printf("%i", card[i]);
    }
printf("\n");

// //reports (via printf) whether it is a valid American Express,MasterCard, or Visa card number

validity(f_number);
}

long get_figs()
{
    long no;
    // TO prompt card [
    do
    {
        no = get_long("Number: ");
        //printf("No.:%ld\n",no);
    }
    while (no < 111111111111111 || no > 9999999999999999);
    //printf("No.to rtrn:%ld\n",no);
  return no;
}

long validity(long f_number)
{
    // To check validity
    if (f_number < 111111111111111 || f_number > 9999999999999999)
        {
        printf("No.to rtrn:%s\n","INVALID");
        }
    else
        {
        printf("No.to rtrn:%s\n","VALID");
        }
    return f_number;
}
