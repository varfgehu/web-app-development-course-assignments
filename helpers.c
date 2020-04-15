#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define UPPER_LIMIT 255

void check_for_upper_limit(int *color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int origi_red, origi_green, origi_blue;
    int new_gray;

    for(int row = 0; row < height; row++ )
    {
        for(int column = 0; column < width; column++)
        {
            origi_red = image[row][column].rgbtRed;
            origi_green = image[row][column].rgbtGreen;
            origi_blue = image[row][column].rgbtBlue;

            new_gray = round(((float)origi_red + (float)origi_green + (float)origi_blue) / 3.0);

            image[row][column].rgbtRed = new_gray;
            image[row][column].rgbtGreen = new_gray;
            image[row][column].rgbtBlue = new_gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int origi_red, origi_green, origi_blue;
    int sepia_red, sepia_green, sepia_blue;

    for(int row = 0; row < height; row++ )
    {
        for(int column = 0; column < width; column++)
        {
            origi_red = image[row][column].rgbtRed;
            origi_green = image[row][column].rgbtGreen;
            origi_blue = image[row][column].rgbtBlue;

            sepia_red = round(((float)origi_red * 0.393) + ((float)origi_green * 0.769) + ((float)origi_blue * 0.189));
            sepia_green = round(((float)origi_red * 0.349) + ((float)origi_green * 0.686) + ((float)origi_blue * 0.168));
            sepia_blue = round(((float)origi_red * 0.272) + ((float)origi_green * 0.534) + ((float)origi_blue * 0.131));

            check_for_upper_limit(&sepia_red);
            check_for_upper_limit(&sepia_green);
            check_for_upper_limit(&sepia_blue);

            image[row][column].rgbtRed = sepia_red;
            image[row][column].rgbtGreen = sepia_green;
            image[row][column].rgbtBlue = sepia_blue;
        }
    }
    return;
}

void check_for_upper_limit(int *color)
{
    if(*color > UPPER_LIMIT)
    {
        *color = UPPER_LIMIT;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int step = 0;
    int tmp_red, tmp_green, tmp_blue;
    int start_index;
    int from, to;
    printf("width: %i\n", width);
    for(int row = 0; row < height; row++)
    {
        //if(0 == width % 2)
        {
            //even
            start_index = ((width + 1) / 2) - 1;
            printf("start_index: %i\n", start_index);

            do
            {
            from = start_index - step;
            to = start_index + (2 * step) + 1;
            //printf("from: %i\n", image[row][from].rgbtRed);
            //printf("to: %i\n", image[row][to].rgbtRed);
            int *tmp = malloc(3 * sizeof(int));
            tmp[0] = image[row][from].rgbtRed;
            tmp[1] = image[row][from].rgbtGreen;
            tmp[2] = image[row][from].rgbtBlue;

            image[row][from].rgbtRed = image[row][to].rgbtRed;
            image[row][from].rgbtGreen = image[row][to].rgbtGreen;
            image[row][from].rgbtBlue = image[row][to].rgbtBlue;

            image[row][to].rgbtRed = tmp[0];
            image[row][to].rgbtGreen = tmp[1];
            image[row][to].rgbtBlue = tmp[2];

            //printf("After reflecting.. \n");
            //printf("from: %i\n", image[row][from].rgbtRed);
            //printf("to: %i\n", image[row][to].rgbtRed);

            free(tmp);

            step++;
            }
            while(start_index == 0);
        }
        //else
        {
            //odd

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
