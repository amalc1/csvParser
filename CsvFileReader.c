#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read and print the header row with a separator
void printHeaderAndSeparator(char *header) {
    char *token = strtok(header, ",");
    int len = 0;

    // Print the header row
    printf("|");
    while (token != NULL) {
        len += strlen(token) + 3;
        printf(" %s |", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    // Print the separator line
    printf("|");
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("|\n");
}

// Function to parse and process CSV data
void parseCSV(FILE *csvFile) {
    char buffer[1000];
    int isHeader = 1;

    // Read and print each line in the file
    while (fgets(buffer, sizeof(buffer), csvFile)) {
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
        
        if (isHeader) {
            printHeaderAndSeparator(buffer);
            isHeader = 0;
        } else {
            // strtok to split each line into fields using ',' as delimiter
            char *token = strtok(buffer, ",");
            printf("|");
            while (token != NULL) {
                // Print each field
                printf(" %s |", token);
                // Move to the next field
                token = strtok(NULL, ",");
            }
            printf("\n");
        }
    }
}

int main(void) {
    // Open csv file in read mode, returns null if cant open
    FILE *csvFile = fopen("sampleCsv.csv", "r");

    if (csvFile == NULL) {
        printf("ERROR: Cannot open file\n");
        // Terminate program with error status
        exit(-1);
    }

    printf("Parsing the CSV file\n");

    // Process CSV file
    parseCSV(csvFile);

    // Close the CSV file
    fclose(csvFile);

    return 0;
}
