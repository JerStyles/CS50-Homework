#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // // print out value before converting
            // printf("BEFORE - R: %x, G: %x, B: %x \n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);

            int grayscale = (int) round((image[i][j].rgbtRed  + image[i][j].rgbtGreen  + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed =  grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;

            // // check value after converting
            // printf("AFTER -  R: %x, G: %x, B: %x \n\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE sepiaColor[3];
    int sepiaTemp[3];
    const float sepiaNumber[3][3] = {
                {0.393, 0.769, 0.189},
                {0.349, 0.686, 0.168},
                {0.272, 0.534, 0.131}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaTemp[0] = image[i][j].rgbtRed;
            sepiaTemp[1] = image[i][j].rgbtGreen;
            sepiaTemp[2] = image[i][j].rgbtBlue;

            // loop through each sepia color: red, green, blue
            for (int k = 0; k < 3; k++)
            {
                float temp = 0.0;

                // multiply each original value with sepiaNumbers
                for (int l = 0; l < 3; l++)
                {
                    temp += sepiaTemp[l] * (float) sepiaNumber[k][l];
                }

                if ((int) round(temp) > 255)
                {
                    temp = 255.00;
                }

                sepiaColor[k] = (int) round(temp);
            }

            image[i][j].rgbtRed = sepiaColor[0];
            image[i][j].rgbtGreen = sepiaColor[1];
            image[i][j].rgbtBlue = sepiaColor[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1, mid = (int) round((width - 1) / 2); j <= mid && k >= mid ; j++, k--)
        {
            RGBTRIPLE temp = image[i][k];
            image[i][k] = image[i][j];
            image[i][j] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurPixel[height][width];
    // calculate blurry pixel and assign to temporary variable
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redTemp = 0, greenTemp = 0, blueTemp = 0;
            float counters = 0.0;

            for (int hStart = i - 1, hEnd = i + 1; hStart <= hEnd ; hStart++)
            {
                if (0 > hStart || height <= hStart)
                {
                    continue;
                }

                for (int wStart = j - 1, wEnd = j + 1; wStart <= wEnd; wStart++)
                {
                    if (0 > wStart || width <= wStart)
                    {
                        continue;
                    }

                    redTemp += image[hStart][wStart].rgbtRed;
                    greenTemp += image[hStart][wStart].rgbtGreen;
                    blueTemp += image[hStart][wStart].rgbtBlue;
                    counters++;
                }

            }

            blurPixel[i][j].rgbtRed = (int) round(redTemp / counters);
            blurPixel[i][j].rgbtGreen = (int) round(greenTemp / counters);
            blurPixel[i][j].rgbtBlue = (int) round(blueTemp / counters);
        }
    }

    // assign blurPixel to original image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurPixel[i][j];
        }
    }
    return;
}
