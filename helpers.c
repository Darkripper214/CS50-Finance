#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == image[i][j].rgbtGreen && image[i][j].rgbtBlue == image[i][j].rgbtRed)
            {
                continue;
            }
            int avg = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed)/3);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int red = round(image[i][j].rgbtRed*0.393 + image[i][j].rgbtGreen*0.769 + image[i][j].rgbtBlue*0.189);
                int green = round(image[i][j].rgbtRed*0.349 + image[i][j].rgbtGreen*0.686 + image[i][j].rgbtBlue*0.168);
                int blue = round(image[i][j].rgbtRed*0.272 + image[i][j].rgbtGreen*0.534 + image[i][j].rgbtBlue*0.131);

                if (red > 255)
                {
                    red = 255;
                }

                if (green > 255)
                {
                    green = 255;
                }

                if (blue > 255)
                {
                    blue = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtRed = red;
            }
        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Scan height
    for (int i = 0; i < height; i++)
    {
        int halfWidth = round((float)1/2 * width);
        for (int j = 0; j < width; j++)
        {

            while (j < halfWidth)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j-1];
                image[i][width - j-1] = temp;
                break;
            }
        }
    }
    return;
}

int blurCheck(int i, int j, int height, int width, int RGB, RGBTRIPLE image[height][width])
{
    float counter = 0;
    int sum = 0;
    for (int x = i - 1; x < (i + 2); x++)
    {
        for (int l = j - 1; l < (j + 2); l++)
        {
            if (x < 0 || l < 0 || x >= height || l >= width)
            {
            }
            else
            {
                if (RGB == 0)
                {
                    sum += image[x][l].rgbtRed;
                }
                else if (RGB == 1)
                {
                    sum += image[x][l].rgbtBlue;
                }
                else
                {
                    sum += image[x][l].rgbtGreen;
                }
                counter++;
            }
        }
    }
    return round(sum / counter);
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blurCheck(i, j, height, width, copy, 0);
            image[i][j].rgbtBlue = blurCheck(i, j, height, width, copy, 1);
            image[i][j].rgbtGreen = blurCheck(i, j, height, width, copy, 2);
        }
    }
    return;
}