#include <cs50.h>
#include <stdio.h>

int main(void)
{

// TODO: Calculate number of years until we reach threshold
int ppl = 9;
int yrs;
for (yrs = 0; ppl < 15; yrs++)
    {
    ppl = ppl + (ppl / 3) - (ppl / 4);
    }
printf("Years: %i\n", yrs);
printf("Population: %i\n", ppl);
}