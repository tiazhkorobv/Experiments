#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
{
//asks for minimum as long as the number is less than 1
int min;
    do
    {
    min = get_int("Minimum: ");
    }
    while (min < 1);

//ask for maximum that is greater than or equal to minimum
int max;
    do
    {
    max = get_int("Maximum: ");
    }
    while (min >= max);

//reassigns i as minimum; as long as minimum is less than or equal to max; print the number then incriment
for (int i = min; i <= max; i++)
    {
    if (prime(i))
        {
        printf("%i\n", i);
        }
    }
}

bool prime(int number)

//take number (which is min); create new int that will loop all numbers from 2 until min; divide min by those numbers
//% should be 1 because number/number=1
for (i = 2; i <= low / 2; ++i) {

         if (low % i == 0) {
            flag = 1;
            break;
         }
      }
for (int j = 2; j <= number; j++)
    {
    if (number % j == 1)
        {
        return true;
        }
    else if (number == 1)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

