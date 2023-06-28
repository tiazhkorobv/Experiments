#include <stdio.h>

int main() {
   int min, max, i, flag;
   printf("Enter two numbers(intervals): ");
   scanf("%d %d", &min, &max);
   printf("Prime numbers between %d and %d are: ", min, max);

   // iteration until min is not equal to max
   while (min < max) {
      flag = 0;

         // ignore numbers less than 2
         if (min <= 1) {
            ++min;
            continue;
         }

         // if min is a non-prime number, flag will be 1
         for (i = 2; i <= min / 2; ++i) {

            if (min % i == 0) {
               flag = 1;
               break;
            }
         }

         if (flag == 0)
            printf("%d ", min);

         // to check prime for the next number
         // increase min by 1
         ++min;
   }

   return 0;
}
