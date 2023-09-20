#include "helpers.h"
#include <math.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

for(int i=0; i<height; i++)
{
    for(int j=0;j<width; j++)
    {
        float avgr = (image[i][j].rgbtRed + image[i][j].rgbtGreen +image[i][j].rgbtBlue)/3.0;
        int avg = round(avgr);
        image[i][j].rgbtRed=avg;
        image[i][j].rgbtBlue=avg;
        image[i][j].rgbtGreen=avg;
    }
}

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
for(int i=0; i<height; i++)
{
    for(int j=0;j<width; j++)
    {

     float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
     float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
     float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

    if (sepiaRed>255)
    {
    image[i][j].rgbtRed = 255;
    }
    else
    {
    image[i][j].rgbtRed = round(sepiaRed);
    }

     if (sepiaBlue>255)
    {
    image[i][j].rgbtBlue = 255;
    }
    else
    {
    image[i][j].rgbtBlue = round(sepiaBlue);
    }

     if (sepiaGreen>255)
    {
    image[i][j].rgbtGreen = 255;
    }
    else
    {
    image[i][j].rgbtGreen = round(sepiaGreen);
    }


    }
}


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
for(int i=0; i<height; i++)
{
    for(int j=0;j<(width)/2; j++)
    {
     RGBTRIPLE temp = image[i][j];
     image[i][j] = image[i][width - (j+1)];
     image[i][width - (j+1)] = temp;

    }

}


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0; i<height; i++)
{
    for(int j=0;j<width; j++)
    {
    temp[i][j] = image[i][j];

    }

}

 for(int i=0; i<height; i++)
 {
     for(int j=0;j<width; j++)
     {
        float count=0.00;
        int tRed =0;
        int tBlue=0;
        int tGreen=0;

    for (int a=-1; a<2; a++)
    {
        for (int b=-1;b <2; b++)
        {
            int curA = i + a ;
            int curB = j + b;

            if(curA<0 || curA>(height-1) || curB<0 || curB>(width-1))
            {
                continue;
            }
            tRed += image[curA][curB].rgbtRed;
            tBlue += image[curA][curB].rgbtBlue;
            tGreen += image[curA][curB].rgbtGreen;

            count++;
        }

    temp[i][j].rgbtRed = round(tRed/count);
    temp[i][j].rgbtBlue = round(tBlue/count);
    temp[i][j].rgbtGreen = round(tGreen/count);


    }

     }

 }
  for(int i=0; i<height; i++)
{
    for(int j=0;j<width; j++)
    {
        image[i][j].rgbtRed =  temp[i][j].rgbtRed;
         image[i][j].rgbtBlue =  temp[i][j].rgbtBlue;
          image[i][j].rgbtGreen =  temp[i][j].rgbtGreen;
    }
}
    return;
}
