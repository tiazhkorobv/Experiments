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
printf("No.===>%ld\n",no);

// Get 1st digit fm last
int no1 = no % 10;
printf("No.0=%i   ",no1);

// Get 2nd digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no2 = no % 10;
printf("No.1=%i   ",no2);

// Get 3rd digit fm last
no = no / 10;
//rintf("No./10=%ld\n",no);
int no3 = no % 10;
printf("No.2=%i   ",no3);

// Get 4th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no4 = no % 10;
printf("No.3=%i\n",no4);

// Get 5th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no5 = no % 10;
printf("No.4=%i   ",no5);

// Get 6th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no6 = no % 10;
printf("No.5=%i   ",no6);

// Get 7th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no7 = no % 10;
printf("No.6=%i   ",no7);

// Get 8th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no8 = no % 10;
printf("No.7=%i\n",no8);

// Get 9th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no9 = no % 10;
printf("No.8=%i   ",no9);

// Get 10th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no10 = no % 10;
printf("No.9=%i   ",no10);

// Get 11th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no11 = no % 10;
printf("No.10=%i  ",no11);

// Get 12th digit fm last
no = no / 10;
printf("No./10= 11th %ld\n",no);
int no12 = no % 10;
printf("No.11=%i  ",no12);
int no12a = no12 * 2 / 10;
printf("No.11a=%i  ",no12a);
int no12b = (no12 * 2) % 10;
printf("No.11b=%i\n",no12b);

// Get 13th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no13 = no % 10;
printf("No.12=%i  ",no13);

// Get 14th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no14 = no % 10;
printf("No.13=%i  ",no14);

// Get 15th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no15 = no % 10;
printf("No.14=%i  ",no15);

// Get 16th digit fm last
no = no / 10;
//printf("No./10=%ld\n",no);
int no16 = no;
printf("No.15=%i\n",no16);


int card [16] = {no1, no2, no3, no4, no5, no6, no7, no8, no9, no10, no11, no12, no13, no14, no15, no16};
/* Multiply every other digit by 2, starting with the
   number’s second-to-last, add those products’ digits together*/
int sum_multd = card [1] * 2 + card [3] * 2 + card [5] * 2 + card [7] * 2 + card [9] * 2 + card [11] * 2 + card [13] * 2 + card [15] * 2;
/* Add the sum to the sum of the digits
     that weren’t multiplied by 2*/
int sum = card [0] + card [2] + card [4] + card [6] + card [8] + card [10] + card [12] + card [14] + sum_multd;



printf("sum: %i\n",sum);
printf("checksum: %i\n",sum % 10);

int i,j;
int size = sizeof(card) / sizeof(card[0]);
for (j = 0; j < 8; j++ )
   {
   printf("[%i] = %i;  ", j, card[j] );
   }
printf("\n");



for (j = 8; j < 16; j++ )
   {
   printf("[%i] = %i; ", j, card[j] );
   }
printf("\n");

for(i = 0; i < size; ++i)
    {
    printf("%i", card[i]);
    }
printf("\n");

    // If the total’s last digit is 0 number is valid!


    /* reports (via printf) whether it is a valid American Express,
       MasterCard, or Visa card number*/
validity(f_number);

}

long get_figs()
{
    long no;
    // TO prompt card No.
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
