#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

if (argc != 2)
{
    printf("usageL ./recover IMAGE\n");
    return 1;
}

 FILE *input_file = fopen(argv[1],"r");

if (input_file ==NULL)
{
    printf("cannot open file");
    return 2;
}

unsigned char buffer[512];

int image_count=0;

FILE *output_file = NULL;

char *fname = malloc(8*sizeof(char));

while (fread(buffer, sizeof(char), 512, input_file))
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0x00)
    {
        sprintf(fname, "%03i.jpg", image_count);

        output_file = fopen(fname,"w");

        image_count++;
    }
    if(output_file != NULL)
    {
        fwrite(buffer,sizeof(char),512,output_file);
    }
}
free(filename);
fclose(output_file);
fclose(input_file);
return 0;
}