#include "helpers.h"
#include <math.h>
#include <stdio.h>

void countValues(int height, int width, int i, int j, RGBTRIPLE image[height][width], RGBTRIPLE blurTemp[height][width]);
void sobelize(int height, int width, int i, int j, RGBTRIPLE image[height][width],  RGBTRIPLE tempImg[height][width]);

// simply Sobel operator into three arrays
const int sobel_indx[3][3] =
{
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int grayPixel;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grayPixel = (int) round(image[i][j].rgbtRed / 3.0 + image[i][j].rgbtGreen / 3.0 + image[i][j].rgbtBlue / 3.0);
            image[i][j].rgbtRed = grayPixel;
            image[i][j].rgbtGreen = grayPixel;
            image[i][j].rgbtBlue = grayPixel;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = (width - 1); j <= k; j++, k--)
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
    RGBTRIPLE blurTemp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            countValues(height, width, i, j, image, blurTemp);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurTemp[i][j];
        }
    }
    return;
}

void countValues(int height, int width, int i, int j, RGBTRIPLE image[height][width], RGBTRIPLE blurTemp[height][width])
{
    int tempRed = 0, tempGreen = 0, tempBlue = 0;
    float counters = 0.0;

    for (int h = (i - 1); h <= i + 1; h++)
    {
        if (h < 0 || h >= height)
        {
            continue;
        }

        for (int w = (j - 1); w <= j + 1; w++)
        {
            if (w < 0 || w >= width)
            {
                continue;
            }

            tempRed += image[h][w].rgbtRed;
            tempGreen += image[h][w].rgbtGreen;
            tempBlue += image[h][w].rgbtBlue;

            counters++;
        }
    }

    blurTemp[i][j].rgbtRed = (int) round(tempRed / counters);
    blurTemp[i][j].rgbtGreen = (int) round(tempGreen / counters);
    blurTemp[i][j].rgbtBlue = (int) round(tempBlue / counters);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // declare temporary variable to store converted values
    RGBTRIPLE tempImg[height][width];

    // loop through every pixel in the original images
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             // convert every single pixel according to sobel operator
             sobelize(height, width, i, j, image, tempImg);
        }
    }

    // assign the temporary value back to final image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImg[i][j];
        }
    }
    return;
}

void sobelize(int height, int width, int i, int j, RGBTRIPLE image[height][width],  RGBTRIPLE tempImg[height][width])
{
    // initiate converted values to default value 0
    int gx[3] = {0, 0, 0}, gy[3] = {0, 0, 0};
    int color[3] = {0, 0, 0};

    // loop throung target pixels' neibouring pixels - 3x3 box
    for (int x = (i - 1), xLimit = (i + 1), row = 0; x <= xLimit && row < 3; x++, row++)
    {
        // for pixels past the vertical edge of the images, skip it
        if (x < 0 || x >= height)
        {
            continue;
        }

        for (int y = (j - 1), yLimit = (j + 1), col = 0; y <= yLimit && col < 3 ; y++, col++)
        {
            // for pixels past the horizontal edge of the images, skip it
            if (y < 0 || y >= width)
            {
                continue;
            }

            // calculate and sum up all gx by multiplying sobel_indx horizontally
            gx[0] += (int) image[x][y].rgbtRed * sobel_indx[row][col];
            gx[1] += (int) image[x][y].rgbtGreen * sobel_indx[row][col];
            gx[2] += (int) image[x][y].rgbtBlue * sobel_indx[row][col];

            // calculate and sum up all gy by multiplying sobel_indx vertically
            gy[0] += (int) image[x][y].rgbtRed * sobel_indx[col][row];
            gy[1] += (int) image[x][y].rgbtGreen * sobel_indx[col][row];
            gy[2] += (int) image[x][y].rgbtBlue * sobel_indx[col][row];

        }
    }

    // find out if converted value > 255, then color = 255
    for (int k = 0; k < 3; k++)
    {
        color[k] = (int) round((float) sqrt(pow(gx[k], 2) + pow(gy[k], 2)));

        if (color[k] > 255)
        {
            color[k] = 255;
        }
    }

    // assign the value to temporary variables
    tempImg[i][j].rgbtRed = color[0];
    tempImg[i][j].rgbtGreen = color[1];
    tempImg[i][j].rgbtBlue = color[2];

    return;
}