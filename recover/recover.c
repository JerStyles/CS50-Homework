#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check input if valid
    if (argc != 2)
    {
        // NOT valid, print message
        printf("Usage: ./recover FILENAME\n");
        return 1;
    }

    // Open card file
    FILE *card = fopen(argv[1], "r");

    // If file not valid
    if (card == NULL)
    {
        printf("File not exists\n");
        return 1;
    }

    // Assign file variables
    FILE *output_file = NULL;
    char *filename = malloc(sizeof(char) * 8);
    uint8_t buffer[512];
    int counter = 0;

    // while NOT end of data
    while (fread(buffer, 1, sizeof(buffer), card) == sizeof(buffer))
    {
        // Search JPG heading
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file
            if (output_file != NULL)
            {
                fclose(output_file);
            }
            // Create a file with a new name

            sprintf(filename, "%03i.jpg", counter);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                perror("Could not create output file");
                fclose(card);
                return 1;
            }

            counter++;
        }

        // Write to output file if open
        if (output_file != NULL) {
            fwrite(buffer, 1, sizeof(buffer), output_file);
        }
    }

    fclose(output_file);
    fclose(card);
    free(filename);
    return 0;
}
