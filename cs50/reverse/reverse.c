#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "wav.h"
// typedef uint8_t   BYTE;
// typedef uint16_t  WORD;
// typedef uint32_t  DWORD;

// typedef struct
// {
//     BYTE   chunkID[4];
//     DWORD  chunkSize;
//     BYTE   format[4];
//     BYTE   subchunk1ID[4];
//     DWORD  subchunk1Size;
//     WORD   audioFormat;
//     WORD   numChannels;
//     DWORD  sampleRate;
//     DWORD  byteRate;
//     WORD   blockAlign;
//     WORD   bitsPerSample;
//     BYTE   subchunk2ID[4];
//     DWORD  subchunk2Size;
// } __attribute__((__packed__))
// WAVHEADER;

int check_format(WAVHEADER bf);
int get_block_size(WAVHEADER bf);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Read header
    WAVHEADER bf;
    fread(&bf, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (check_format(bf))
    {
        printf("Input is not a WAV file.\n");
        fclose(inptr);
        return 3;
    }

    // Open output file for writing
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 4;
    }

    //6. Write header to file
    fwrite(&bf, sizeof(WAVHEADER), 1, outptr);

    //7. Use get_block_size to calculate size of block
    int block_size = get_block_size(bf);

    //8. Write reversed audio to file
    BYTE *buffer = malloc(block_size);
    int num_blocks = bf.subchunk2Size / block_size;

    // Move the file pointer to the end of the file
    fseek(inptr, 0, SEEK_END);

    // Iterate backward through data, block by block
    for (int i = num_blocks - 1; i >= 0; i--)
    {
        // Move the file pointer back two block sizes to read the previous block
        fseek(inptr, -(2 * block_size), SEEK_CUR);

        // Read a block from the input file
        fread(buffer, sizeof(buffer), block_size, inptr);

        // Write the block to the output file in reverse order
        for (int j = block_size - 1; j >= 0; j--)
        {
            fwrite(&buffer[j], sizeof(buffer), 1, outptr);
        }
    }

    // Move the file pointer back to the beginning of the file
    fseek(inptr, 0, SEEK_SET);

    // clean up
    free(buffer);
    fclose(inptr);
    fclose(outptr);
    return 0;
}


int check_format(WAVHEADER header)
{
    // Check if the file is in WAV format
    if (header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' || header.format[3] != 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // Calculate size of block
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}