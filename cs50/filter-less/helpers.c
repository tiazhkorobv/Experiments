#include "helpers.h"
#include <math.h>
//******** Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average values (grey)
            int grey = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set pixel's new RGB values to sepia values
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate new sepia values
            int sepiaRed = (int)(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue + 0.5);
            int sepiaGreen = (int)(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue + 0.5);
            int sepiaBlue = (int)(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue + 0.5);

            // Cut off values at 255
            sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
            sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

            // Set new sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)// check only left half of all pixels need
        {
            // Swaping opposite pixels
            RGBTRIPLE stored = image[i][j];//tmp storage before swapping for left pixel
            image[i][j] = image[i][width - j - 1];//reassign right pixel to left
            image[i][width - j - 1] = stored;//reassign left pixel from storage to right
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copying original image
    RGBTRIPLE copy[height][width];
    // Initialize variables to calculate the average color

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j]; //pexel by pixel
        }
    }

    // bluring original iterating through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ttl_R = 0, ttl_G = 0, ttl_B = 0, gttl = 0;
            // Calculate the average color of the 3x3 box around the current pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int column = j + l;
                    if (row >= 0 && row < height && column >= 0 && column < width)//ensures that only pixels that are within the
                        //boundaries of the image are included in the average calculation
                    {
                        // get average color of the box
                        ttl_R += copy[row][column].rgbtRed;
                        ttl_G += copy[row][column].rgbtGreen;
                        ttl_B += copy[row][column].rgbtBlue;
                        gttl++;
                    }
                }
            }

            // replace the color of the current pixel in the output image to the average color
            image[i][j].rgbtRed = round((float) ttl_R / gttl);
            image[i][j].rgbtGreen = round((float) ttl_G / gttl);
            image[i][j].rgbtBlue = round((float) ttl_B / gttl);
        }
    }
}

