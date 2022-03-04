#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

int idgenarate(){
    FILE *filepointer;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        printf("idgenarate.txt failed to open");
        exit(EXIT_FAILURE);
    }
    else{
        printf("opening idgenarate.txt...");
    }
    char temp[MAX];
    fgets(temp, sizeof(temp), filepointer);
    fseek(filepointer, 0, SEEK_END);
    int memory =  ftell(filepointer);
    fseek(filepointer, 0, SEEK_SET);
    int i = 0;
    if(memory == 0){
        i = 1;
        printf("Writing mode activated.\n");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "w");
        fprintf(filepointer,"%d", i);
        fclose(filepointer);
    }
    else{
        i = atoi(temp);
        i = i + 1;
        printf("Writing mode activated.\n");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "w");
        fprintf(filepointer,"%d", i);
        fclose(filepointer);
    }
    return i;
}

int main(){
    printf("%d", idgenarate());
    return 0;
}