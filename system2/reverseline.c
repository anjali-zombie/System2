#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to reverse a string in place
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to read and reverse the first line of a CSV file
void reverse_first_line(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[BUFFER_SIZE];
    // Read the first line
    if (fgets(line, sizeof(line), file) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Reverse the line
        reverse_string(line);
        
        // Print the reversed line
        printf("Reversed line: %s\n", line);
    } else {
        printf("Error reading the first line or file is empty\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "student.csv";
    reverse_first_line(filename);
    return 0;
}

