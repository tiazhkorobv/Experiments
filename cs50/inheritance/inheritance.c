// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person - takes a size as argument and will allocate n bytes
    person *new = malloc(sizeof(person));
    // If there are still generations left to create
    if (generations > 1)
    {
        // Create (incl. allocation memory tks recursion) two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: set the parent pointers of the new person you created.
        new->parents[0] = parent0;
        new->parents[1] = parent1;
        // TODO: assign both alleles for the new person by randomly choosing one allele from each parent.
        new->alleles[0] = parent0->alleles[rand() % 2];//This function returns an integer between 0 and RAND_MAX, or 2147483647
        new->alleles[1] = parent1->alleles[rand() % 2];//to generate a pseudorandom number 0 or 1, use the expression rand() % 2.
    }

    // If there are no generations left to create
    else
    {
        // TODO:  then there will be no parent data for this person. Set parent pointers to NULL
        new->parents[0] = NULL;
        new->parents[1] = NULL;
        // TODO: and Randomly assign alleles
        new->alleles[0] = random_allele();//
        new->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    //return NULL;
    return new;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p) //accept as input a pointer to a person
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }
    // TODO: Free parents recursively -free memory for all of their ancestors
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    // TODO: Free child - free memory for  person
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // If the input to the function is NULL, then there’s nothing to free, so your function can return immediately.
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
