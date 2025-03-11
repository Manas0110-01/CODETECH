#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run Length Encoding (RLE)
void compressRLE(const char *input, const char *output) {
    FILE *inFile = fopen(input, "r");
    FILE *outFile = fopen(output, "w");

    if (inFile == NULL || outFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char current, prev;
    int count = 1;

    prev = fgetc(inFile);

    while ((current = fgetc(inFile)) != EOF) {
        if (current == prev) {
            count++;
        } else {
            fprintf(outFile, "%c%d", prev, count);
            prev = current;
            count = 1;
        }
    }

    // Write the last character and its count
    if (prev != EOF) {
        fprintf(outFile, "%c%d", prev, count);
    }

    fclose(inFile);
    fclose(outFile);

    printf("Compression completed. Output saved to %s\n", output);
}

// Function to decompress RLE encoded data
void decompressRLE(const char *input, const char *output) {
    FILE *inFile = fopen(input, "r");
    FILE *outFile = fopen(output, "w");

    if (inFile == NULL || outFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    int count;

    while (fscanf(inFile, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);

    printf("Decompression completed. Output saved to %s\n", output);
}

int main() {
    char inputFile[100], outputFile[100];
    int choice;

    printf("Run Length Encoding (RLE) Program\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressRLE(inputFile, outputFile);
    } else if (choice == 2) {
        decompressRLE(inputFile, outputFile);
    } else {
        printf("Invalid choice. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
