#include <cs50.h>
#include <stdio.h>

int main(void)
{

// TODO: Prompt for start size
int crnt;
  do
  {
      crnt = get_int("Input current population (more than 9!): ");
  }
  while (crnt < 9);

// TODO: Prompt for end size
int ftr;
    do
    {
        ftr = get_int("Input future population: ");
    }
    while (ftr <= crnt);

// TODO: Calculate number of years until we reach threshold
 
for (int ppl = crnt; ppl < ftr; ppl = ppl + (ppl / 3) - (ppl / 4))
    {
     for (int yrs = 0; ppl < ftr; yrs++)
        {
        printf("Years: %i\n", yrs);
        }
    // TODO: Print number of years
printf("Yea5555rs: %i\n", yrs);
    }
