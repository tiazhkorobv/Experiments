#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];
    // Create array to store plate numbers
    //char *plates[8];
    char **plates = malloc(8 * sizeof(char*));
    //create a file pointer to our external text file
    FILE *infile = fopen(argv[1], "r");
    //create a variable to hold the index of each array element
    int idx = 0;
    //reading the file and saving the plate numbers to the array
    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        //plates[idx] = buffer;
        // Allocate memory for plate string and copy buffer contents
        //first allocate memory for the plates array using malloc,
        //and then inside the while loop, we allocate memory for each
        //plate string using malloc and copy the buffer contents using strcpy.
        //This ensures that each plate string in the plates array is separate
        //from the buffer and from each other.
        plates[idx] = malloc(strlen(buffer) + 1);

        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    // new! Free memory allocated for plates array and plate strings
    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }
    free(plates);

    // Close input file
    fclose(infile);

    return 0;
}
