#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int height = get_int("Height: ");

  int o = 1;

  while (height<1 || height>8)
  {
    height = get_int("Height: ");
  }

 if (height ==1)
 {
    printf("#\n");
 }
 else
 {

  for (int i=1; i<=height; i++)
  {
    for(int k=0; k<(height-o); k++)
    {
        printf(" ");
    }
  o += 1;
    int l = 0;
      while (l<i)
      {
        l += 1;
        printf("#");
      }
    printf("\n");
  }

 }
}