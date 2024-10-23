#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAXWORDS 20

int splitWords(char *str, char *words[]);
int isDuplicate(char *words[], int count, const char *word);
void printUniqueWords(char *words[], int count);

int main() {
    char str[MAX];
    char *words[MAXWORDS];
    
    printf("Enter pipe-separated sequence of words:\n");
    fgets(str, MAX - 1, stdin);

    // Remove trailing newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int count = splitWords(str, words);
    printUniqueWords(words, count);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }

    return 0;
}

int splitWords(char *str, char *words[]) {
    int count = 0;
    char *token = strtok(str, "|");

    while (token != NULL) {
        // Allocate memory and copy the token
        words[count] = (char *)malloc(strlen(token) + 1);
        if (words[count] == NULL) {
            perror("Unable to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, "|");
    }

    return count;
}

int isDuplicate(char *words[], int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], word) == 0) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate found
}

void printUniqueWords(char *words[], int count) {
    for (int i = 0; i < count; i++) {
        if (!isDuplicate(words, i, words[i])) {
            if (i > 0) {
                printf("|");
            }
            printf("%s", words[i]);
        }
    }
    printf("\n");
}

