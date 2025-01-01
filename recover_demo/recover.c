#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILENAME_LENGTH 12 // Maximum filename length is 8 + 3 (".jpg") + 1 (null terminator)

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover FILE\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Could not open input file");
        return 1;
    }

    // Variables for output file handling
    FILE *output_file = NULL;
    char filename[FILENAME_LENGTH];
    uint8_t buffer[512];
    int count_image = 0;

    // Process input file
    while (fread(buffer, 1, sizeof(buffer), input_file) == sizeof(buffer)) {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Close previous output file if open
            if (output_file != NULL) {
                fclose(output_file);
            }

            // Create filename for output file
            snprintf(filename, FILENAME_LENGTH, "%03i.jpg", count_image++);

            // Open new output file
            output_file = fopen(filename, "w");
            if (output_file == NULL) {
                perror("Could not create output file");
                fclose(input_file);
                return 1;
            }
        }

        // Write to output file if open
        if (output_file != NULL) {
            fwrite(buffer, 1, sizeof(buffer), output_file);
        }
    }

    // Close input and output files
    fclose(input_file);
    if (output_file != NULL) {
        fclose(output_file);
    }

    return 0;
}
