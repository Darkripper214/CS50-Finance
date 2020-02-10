#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// definitions
#define BUFSIZE 512
typedef uint8_t BYTE;

// functions
bool find_JPEG(BYTE[]);
FILE* newfile(FILE*, char[], int, BYTE[]);

int main(int argc, char* argv[])
{
    // check correct usage of program
    if (argc != 2)
    {
        fprintf(stderr, "Error!: must be in format ./recover xxx.raw");
        return 1;
    }

    // open file
    char* input = argv[1];
    FILE* infile = fopen(input, "r");


    // check file is in right format
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", input);
        return 2;
    }

    BYTE buffer[BUFSIZE];
    int JPEG_counter = 0;
    char filename [8];
    FILE* img = NULL;


    while (!feof(infile) && fread(&buffer, BUFSIZE, 1, infile) == true)
    {
        //  start if image is there
        if (find_JPEG(buffer) == true)
        {
            // special case for first image
            if (JPEG_counter == 0)
            {
                // start new file
                sprintf(filename, "%03i.jpg", JPEG_counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BUFSIZE, img);
                JPEG_counter++;
            }
            // if not first image
            else
            {
                // close current file
                fclose(img);

                // start new file
                sprintf(filename, "%03i.jpg", JPEG_counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BUFSIZE, img);
                JPEG_counter++;
            }
        }

        // if there are no new jpeg
        if (find_JPEG(buffer) == false)
        {
            // continue to next buffer
            if (JPEG_counter == 0)
            {
                continue;
            }
            else
               // else write to file
            {
                fwrite(buffer, 1, BUFSIZE, img);
            }
        }
    }

    if (feof(infile))
    {
        fclose(infile);
    }

    return 0;
}


bool find_JPEG(BYTE buffer[])
{
// check if JPEG
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }

    else
    {
        return false;
    }
}


FILE* newfile(FILE* img, char filename[], int JPEG_counter, BYTE buffer[])
{
    sprintf(filename, "%03i.jpg", JPEG_counter);
    img = fopen(filename, "w");
    fwrite(buffer, 1, BUFSIZE, img);
    return img;
}