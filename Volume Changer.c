// This code is in the programming language C. This program was built as many videos have low volume, especially for students doing online school. I wanted to be able to affect the volume of a video so a student would be able to hear the teacher better. This is similiar to what your computer does when you click "increase" or "decrease" sound.

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_to header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fprint(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer
    while (fread(&buffer, sizeof(int16_t)), 1, input)
    {
        buffer*=factor
        fwrite(&buffer, sizeof(int_16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
