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
// void sepia(int height, int width, RGBTRIPLE image[height][width])
// {
//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             // Calculate new sepia values
//             int sepiaRed = (int)(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue + 0.5);
//             int sepiaGreen = (int)(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue + 0.5);
//             int sepiaBlue = (int)(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue + 0.5);

//             // Cut off values at 255
//             sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
//             sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
//             sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

//             // Set new sepia values
//             image[i][j].rgbtRed = sepiaRed;
//             image[i][j].rgbtGreen = sepiaGreen;
//             image[i][j].rgbtBlue = sepiaBlue;
//         }
//     }
// }


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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // create a copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // define the Sobel operators
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // iterate through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            int Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            // iterate through each surrounding pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int column = j + l;

                    // check if the surrounding pixel is within the image bounds
                    if (row >= 0 && row < height && column >= 0 && column < width)
                    {
                        int weight_x = Gx[k + 1][l + 1];
                        int weight_y = Gy[k + 1][l + 1];

                        Gx_red += weight_x * copy[row][column].rgbtRed;
                        Gx_green += weight_x * copy[row][column].rgbtGreen;
                        Gx_blue += weight_x * copy[row][column].rgbtBlue;

                        Gy_red += weight_y * copy[row][column].rgbtRed;
                        Gy_green += weight_y * copy[row][column].rgbtGreen;
                        Gy_blue += weight_y * copy[row][column].rgbtBlue;
                    }
                }
            }

            // calculate the edge strength and direction
            int red = round(sqrt(pow(Gx_red, 2) + pow(Gy_red, 2)));
            int green = round(sqrt(pow(Gx_green, 2) + pow(Gy_green, 2)));
            int blue = round(sqrt(pow(Gx_blue, 2) + pow(Gy_blue, 2)));

            // cap the values at 255
            red = (red > 255) ? 255 : red;
            green = (green > 255) ? 255 : green;
            blue = (blue > 255) ? 255 : blue;

            // set the pixel columnor to the calculated value
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

