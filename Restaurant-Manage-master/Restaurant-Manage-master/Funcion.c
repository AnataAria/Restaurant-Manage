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

typedef struct
{
    char ID[MAX];
    char userName[128];
    char date[128];
    char tableNumber[128];
    char chooseFood[128];
    char sum[128];
}CustomerOrderInfoInput;

typedef struct {
    char number[128];
    char foodName[128];
    char prizes[128];
}FoodMenu;

void foodMenuUpload(FoodMenu a[]){
    FILE *filepointer;
    filepointer = fopen("foodmenu.csv", "r");
    if(filepointer == NULL){
        printf("Opening file foodmenu.csv failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening file foodmenu.csv...");
    }
    char buf[MAX], *temp;
    fgets(buf, sizeof(buf),filepointer);
    int i = 0;
    while (fgets(buf, sizeof(buf), filepointer) != NULL){
        temp = strtok(buf, ",");
        strcpy(a[i].number, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].foodName, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].prizes, temp);

        i++;
    }
    fclose(filepointer);
}

void searchFood(FoodMenu a[],CustomerOrderInfo b[]){
    FILE *filepointer;
    FILE *filepointer1;
    filepointer = fopen("foodmenu.csv", "r");
    if(filepointer == NULL){
        printf("Couldn't open file 'foodmenu.csv\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening file 'foodmenu.csv'...\n");
    }
}

int idgenarate(CustomerOrderInfo a[]){
    FILE *filepointer;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        printf("idgenarate.txt failed to open");
        exit(EXIT_FAILURE);
    }
    else{
        printf("opening idgenarate.txt...\n");
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

int readHistoryID(){
    int i = 0;
    FILE *filepointer ;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        printf("Couldn't open idgenarate.txt");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening idgenarate.txt");
    }
    char temp[MAX];
    fgets(temp, sizeof(temp), filepointer);
    if(temp == NULL){
        exit(EXIT_SUCCESS);
    }
    else{
        i = atoi(temp);
    }

    return i;
}

void uploadOnline(CustomerOrderInfo a[])
{
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if (filepointer == NULL){
        printf("Error opening CSV file\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening...\n");
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

void uploadToFile(CustomerOrderInfo a[], const int count){ // used if there have something change to struct
    int temp = count;
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "w");
    if(filepointer == NULL){
        printf("Error: Could not open CustomerOrderInfo.csv");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening CustomerOrderInfo.csv...");
    }

    int line = 0;
    fprintf(filepointer, "ID,UserName,Date,TableNumber,ChooseFood,Prizes\n");
    while(line <= temp){
        fprintf(filepointer,"%s,%s,%s,%s,%s,%s\n", a[line].ID,a[line].userName,a[line].date,a[line].tableNumber,a[line].chooseFood,a[line].sum);
        line ++;
    }
    fclose(filepointer);
}

void moveData(CustomerOrderInfo a[], CustomerOrderInfoInput b){
    int i = atoi(b.ID);
    strcpy(a[i].ID, b.ID);
    strcpy(a[i].userName, b.userName);
    strcpy(a[i].date, b.date);
    strcpy(a[i].tableNumber, b.tableNumber);
    strcpy(a[i].chooseFood, b.chooseFood);
    strcpy(a[i].sum, b.sum);
    uploadToFile(a, i);
}

void backupData(CustomerOrderInfo a[]){
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfoBackup.csv","w");
    if(filepointer == NULL){
        printf("ERROR: Failed to open CustomerOrderInfoBackup.csv\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening CustomerOrderInfoBackup.csv");
    }
    fprintf(filepointer, "ID,UserName,Date,TableNumber,ChooseFood,Prizes");
    int count = readHistoryID();
    int cout = 0;
    while(cout < count){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s\n",a[cout].ID,a[cout].userName,a[cout].date,a[cout].chooseFood,a[cout].sum," " );
        cout ++;
    }
    fclose(filepointer);
}

void caculateSummary(CustomerOrderInfoInput a[],FoodMenu b[]){
    
}

int main(){
    FoodMenu a[MAX];
    CustomerOrderInfo b[MAX];
    foodMenuUpload(a);
    uploadOnline(b);
    
    return 0;
}









