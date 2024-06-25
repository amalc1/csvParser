#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse and process CSV data
void  parseCSV(FILE *csvFile) {
    char *data;
    char buffer[1000];
    // Read and print each line in the file
    while (fgets(buffer, sizeof(buffer), csvFile)) {
        // strtok to split each line into fields using , as delimiter
        data = strtok(buffer, ",");
        while (data != NULL) {
            // Print each field
            printf(" %s ", data);
            // Move to the next field
            data = strtok(NULL, ",");
        }
    }
}

int main(void) {    
    // Open csv file in read mode, returns null if cant open
    FILE *csvFile = fopen("sampleCsv.csv", "r");

    if (csvFile == NULL) {
        printf("ERROR: Cannot open file\n");
          // terminate pgm with err status
        exit(-1); 
    }

    printf("Parsing the CSV file\n");
    printf("-----------------------------\n");

    // Process CSV file
    parseCSV(csvFile);

    // Close the CSV file
    fclose(csvFile);
    printf("\n-----------------------------\n");

    return 0;
}





 
