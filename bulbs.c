#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string text = get_string("Message: ");

    for (int i=0; i<strlen(text); i++)
    {
        int bin[]={0,0,0,0,0,0,0,0};

        int deci= text[i];
        int n=0;

        while (deci>0)
        {
            bin[n]= deci % 2;
            deci /= 2;
            n++;
        }

        for (int l= BITS_IN_BYTE-1; l >=0; l--)
        {
            print_bulb(bin[l]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
