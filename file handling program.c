#include <stdio.h>
#include <stdlib.h>

void create_and_write_file(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open in write mode (creates new file)
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Enter data to write to the file (end with CTRL+D on Unix/Linux or CTRL+Z on Windows):\n");

    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, file); // Write character to file
    }

    fclose(file);
    printf("Data written successfully.\n");
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open in read mode
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("File contents:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Display character
    }

    fclose(file);
}

void append_to_file(const char *filename) {
    FILE *file = fopen(filename, "a"); // Open in append mode
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Enter data to append to the file (end with CTRL+D on Unix/Linux or CTRL+Z on Windows):\n");

    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, file); // Append character to file
    }

    fclose(file);
    printf("Data appended successfully.\n");
}

int main() {
    char filename[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); // Consume newline left by scanf

    while (1) {
        printf("\nFile Operations:\n");
        printf("1. Create and Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                create_and_write_file(filename);
                break;
            case 2:
                read_file(filename);
                break;
            case 3:
                append_to_file(filename);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}