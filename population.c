#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n=0;

    int startS = get_int("Start Size:");

    while (startS < 9)
    {
        startS = get_int("Start Size:");
    }

    int endS = get_int("End Size:");

    while (endS < startS)
    {
         endS = get_int("End Size:");
    }

    while (startS<endS)
    {
        n += 1;
        int l = (startS/3);
        int k = (startS/4);
        startS += l;
        startS -= k;
    }

    printf("Years: %i",n);
}
