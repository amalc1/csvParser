#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char buffer[1000];
    char *data;
    // Open csv file in read mode, returns null if cant open
    FILE *csvFile = fopen("wrongCsvTest.csv", "r");

    if(csvFile == NULL){
        printf("ERROR: cant open file \n");
        // terminate pgm with err status
        exit(-1); 
    }

    printf("Opening the file\n");
    printf("-----------------------------\n");

     // Read and print each line in the file
    while(fgets(buffer, sizeof(buffer), csvFile)){
        printf("%s\n", buffer);
    }



    //close the csv file
    fclose(csvFile);
    printf("\n-----------------------------\n");
    return 0;
}
    