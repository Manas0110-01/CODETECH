#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// Keywords list
const char *keywords[] = {"int", "float", "if", "else", "while", "return", "for", "char"};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<' || ch == '!');
}

// Function to process the input file and identify tokens
void lexicalAnalyzer(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    char token[MAX_TOKEN_LENGTH];
    int index = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            token[index++] = ch;
        } else {
            if (index > 0) {
                token[index] = '\0';
                if (isKeyword(token)) {
                    printf("Keyword: %s\n", token);
                } else {
                    printf("Identifier: %s\n", token);
                }
                index = 0;
            }

            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);

                // Check for multi-character operators
                char next = fgetc(file);
                if ((ch == '>' || ch == '<' || ch == '=' || ch == '!') && next == '=') {
                    printf("Operator: %c%c\n", ch, next);
                } else {
                    ungetc(next, file);
                }
            }
        }
    }

    fclose(file);
}

int main() {
    char filename[100];

    printf("Enter the input file name: ");
    scanf("%s", filename);

    lexicalAnalyzer(filename);

    return 0;
}
