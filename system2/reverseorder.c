/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_LINES 1000

// Function to reverse the order of lines
void reverse_lines(const char *input_filename, const char *output_filename) 
{
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        perror("Error opening input file");
        return;
    }

    // Read all lines into an array
    char *lines[MAX_LINES];
    int line_count = 0;

    while (fgets(lines[line_count], BUFFER_SIZE, input_file) != NULL) 
    {
        // Remove trailing newline if present
        size_t len = strlen(lines[line_count]);
        if (len > 0 && lines[line_count][len - 1] == '\n') 
	{
            lines[line_count][len - 1] = '\0';
        }
        line_count++;
        if (line_count >= MAX_LINES) 
	{
            fprintf(stderr, "Exceeded maximum number of lines\n");
            break;
        }
    }

    fclose(input_file);

    // Open the output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) 
    {
        perror("Error opening output file");
        return;
    }

    // Write the lines in reverse order
    for (int i = line_count - 1; i >= 0; i--)
    {
        fprintf(output_file, "%s\n", lines[i]);
    }

    fclose(output_file);
}

int main()
{
    const char *input_filename = "student.csv";
    const char *output_filename = "reversed_data.csv";
    reverse_lines(input_filename, output_filename);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_COLUMNS 10
#define MAX_LINES 1000

// Function to split a line into columns based on delimiter
int split_line(const char *line, char *columns[], char delimiter) {
    int count = 0;
    char *token = strtok(line, &delimiter);
    while (token != NULL && count < MAX_COLUMNS) {
        columns[count++] = token;
        token = strtok(NULL, &delimiter);
    }
    return count;
}

// Function to reverse column order
void reverse_columns(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return;
    }

    char header[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    char *header_columns[MAX_COLUMNS];
    char *data_columns[MAX_COLUMNS];

    // Read and split the header line
    if (fgets(header, sizeof(header), input_file) != NULL) {
        size_t len = strlen(header);
        if (len > 0 && header[len - 1] == '\n') {
            header[len - 1] = '\0'; // Remove trailing newline
        }
        int num_columns = split_line(header, header_columns, ',');

        // Define the new order of columns (reverse order)
        int new_order[] = {3, 2, 1, 0}; // Example for 4 columns

        // Write the new header to the output file
        for (int i = 0; i < sizeof(new_order) / sizeof(new_order[0]); i++) {
            fprintf(output_file, "%s", header_columns[new_order[i]]);
            if (i < sizeof(new_order) / sizeof(new_order[0]) - 1) {
                fprintf(output_file, ",");
            }
        }
        fprintf(output_file, "\n");

        // Process and write each data line
        while (fgets(line, sizeof(line), input_file) != NULL) {
            len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0'; // Remove trailing newline
            }
            int num_data_columns = split_line(line, data_columns, ',');

            // Write the data in the new column order
            for (int i = 0; i < sizeof(new_order) / sizeof(new_order[0]); i++) {
                fprintf(output_file, "%s", data_columns[new_order[i]]);
                if (i < sizeof(new_order) / sizeof(new_order[0]) - 1) {
                    fprintf(output_file, ",");
                }
            }
            fprintf(output_file, "\n");
        }
    } else {
        fprintf(stderr, "Error reading header line\n");
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    const char *input_filename = "data.csv";
    const char *output_filename = "reversed_columns.csv";
    reverse_columns(input_filename, output_filename);
    return 0;
}

