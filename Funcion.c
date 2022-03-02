#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

typedef struct
{
   char ID[MAX];
   char userName[128];	
   char date[128];
   char tableNumber[128];
   char chooseFood[128];
   char sum[128];
}CustomerOrderInfo;

typedef struct {
    char stt[MAX];
    char foodName[128];
    char prizes[128];
}FoodMenu;

void idgenarate(CustomerOrderInfo a[])

void uploadOnline(CustomerOrderInfo a[])
{
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if (filepointer == NULL){
        printf("Error opening CSV file");
        exit(-1);
    }
    else{
        printf("Opening...");
    }

    char buf[MAX], *temp;
    int i = 0;
    fgets(buf, sizeof(buf), filepointer);
    while (fgets(buf, sizeof(buf), filepointer) != NULL) {
        temp = strtok(buf, ",");
        strcpy(a[i].ID , temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].userName, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].date, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].tableNumber, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].chooseFood, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].sum, temp);

        i++;
    }
    fclose(filepointer);
}

void uploadToFile(CustomerOrderInfo a[]){ // used if there have something change to struct
    int count = 0;
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "w");
    if(filepointer == NULL){
        printf("Error: Could not open");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening...");
    }
    
    int line = 0;
    if(line == 0){
        fprintf(filepointer, "ID,UserName,Date,TableNumber,ChooseFood,Prizes\n");
    }
    int size = 0;
    size = sizeof(a) / 48;
    int i = 0;
    while(line <= size){
        fprintf(filepointer,"%s,%s,%s,%s,%s,%s\n", a[i].ID,a[i].userName,a[i].date,a[i].tableNumber,a[i].chooseFood,a[i].sum);
        i++;
    }
}

void addDataToFile(CustomerOrderInfo a[]){

}

void addDataToStruct(CustomerOrderInfo a[]){

}

void backupData(){
    
}

void caculateSummary(CustomerOrderInfo a[],FoodMenu b[]){

}

int main(){

}









