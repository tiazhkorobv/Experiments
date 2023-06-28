#include <cs50.h>
#include <stdio.h>

int main(void)
{

// TODO: Prompt for start size
int crnt;
  do
  {
      crnt = get_int("Input current population (at least 9!): ");
  }
  while (crnt < 9);

// TODO: Prompt for end size
int ftr;
    do
    {
        ftr = get_int("Input future population: ");
    }
    while (ftr < crnt);

// TODO: Calculate number of years until we reach threshold
int ppl = crnt;
int yrs;
for (yrs = 0; ppl < ftr; yrs++)
    {
    ppl = ppl + (ppl / 3) - (ppl / 4);
    }
printf("Years: %i\n", yrs);
}