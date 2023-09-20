#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for(int k=0; k<width; k++)
        {
            if (image[i][k].rgbtRed == 0 && image[i][k].rgbtGreen == 0 && image[i][k].rgbtBlue == 0)
            {
                image[i][k].rgbtGreen = 0xff;
            }
        }
    }
}
