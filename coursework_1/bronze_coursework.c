#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {

    // INPUT LINE FROM THE FILE, THEN DELIMITER (WHAT CHAR SEPARATES EACH FIELD)
    // OTHER INPUTS ARE POINTERS
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit;
    }
    return file;

}

// Complete the main functions
int main() {
    char filename [] = "FitnessData_2023.csv";
    FILE *file = open_file(filename, "r");
    char character = fgetc(file);
    int line = 1;

    FITNESS_DATA arr[200];
    int buffer_size = 200;
    char line_buffer[buffer_size];

    //TEMP STORAGE
    char date[100];
    char time[100];
    char steps[100];

    while (fgets(line_buffer, buffer_size, file) != NULL){
        tokeniseRecord(line_buffer,",",date,time,steps);
         
        strcpy(arr[line].date, date);
        strcpy(arr[line].time, time);
        arr[line].steps = atoi(steps);
        
        
        if (line < 4){
            printf("%s/%s/%d\n",arr[line].date, arr[line].time, arr[line].steps); 
        }
        
       

        line = line + 1;
        
    }
    printf("\n");
    printf("Number of records in file:  %d ", line);

    fclose(file);
    
    return 0;



}