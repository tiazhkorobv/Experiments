#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover image\n");
        return 1;
    }

    // Open forensic image for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Image %s cannot be opened for reading\n", argv[1]);
        return 1;
    }

    // Allocate memory for buffer
    BYTE *buffer = malloc(BLOCK_SIZE); //initialize a BYTE variable with the return value of malloc() * pointer
    if (buffer == NULL)
    {
        fclose(input);
        //fprintf(stderr, "Out of memory\n");
        return 1;
    }

    // Initialize variables
    int files = 0;
    FILE *output = NULL;
    char file_name[FILE_NAME_SIZE];

    // Read blocks of data from input file
    while (fread(buffer, BLOCK_SIZE, 1, input) == 1)
    {
        // Check if block starts with a JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0)//the fourth byte’s first four bits "...  & 0xf0" is 1110"
        {
            // Close previous output file (if any)
            if (output != NULL)
            {
                fclose(output);
            }

            // Generate file name for new output file
            sprintf(file_name, "%03d.jpg", files);//prints a “formatted string” to a location in memory
            files++;

            // Open new output file for writing
            output = fopen(file_name, "w");
            if (output == NULL)
            {
                fclose(input);
                free(buffer); //must not leak any memory.
                fprintf(stderr, "Could not create %s\n", file_name);
                return 1;
            }
        }

        // Write block to output file
        if (output != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    // Close input and output files
    if (output != NULL)
    {
        fclose(output);
    }

    // Free memory for buffer
    fclose(input);
    free(buffer);

    return 0;
}
