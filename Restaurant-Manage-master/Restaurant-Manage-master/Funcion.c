#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 1000

typedef struct
{
   char ID[MAX]; // ID or Order ID of customer
   char userName[128]; //	Name of Customer
   char date[128]; // Date order created
   char tableNumber[128]; // Number of table have order 
   char chooseFood[128]; // Food have order
   char sum[128]; // Summarized of money
}CustomerOrderInfo; // This is struct where Customer Order Infomation is upload from file

typedef struct
{
    char ID[MAX]; // ID or Order ID of customer have inputs
    char userName[128]; // Name of user have input 
    char date[128]; // Date order create have input
    char tableNumber[128]; // Number of table have input
    char chooseFood[128]; // Food have order
    char sum[128]; // Summarized of money
}CustomerOrderInfoInput; // This is struct where Customer Order Info data is upload from UI

typedef struct {
    char number[128];
    char foodName[128];
    char prizes[128];
}FoodMenu;  // This is struct where food menu is upload from file 

void foodMenuUpload(FoodMenu a[]); // Upload food menu from file csv to struct

void backupData(CustomerOrderInfo a[]); //use for backupdata when reading file csv is error

void uploadOnline(CustomerOrderInfo a[]); // upload customer data from file csv to struct

int idgenarate(); // it's used to genarate ID

int readHistoryID(); // Take ID from history of ID

void uploadToFile(CustomerOrderInfo a[],const int count); //Upload data from CustomerOrderInfo to file csv

void moveData(CustomerOrderInfo a[],CustomerOrderInfoInput b); //move data from CustomerOrderInfoInput to CustomerOrderInfo

int calculateSummary(CustomerOrderInfoInput a, FoodMenu b[],CustomerOrderInfo c[]); //calculateSummary of money

void customerInfoInput(char ID[], char userName[],char date[], char tableNumber[],char chooseFood[],char sum[],CustomerOrderInfoInput a);
//------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    CustomerOrderInfo a[MAX];
    FoodMenu b[MAX];
    CustomerOrderInfoInput c;

    uploadOnline(a);
    foodMenuUpload(b);


    return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void foodMenuUpload(FoodMenu a[]){
    FILE *filepointer;
    filepointer = fopen("foodmenu.csv", "r");
    if(filepointer == NULL){
        printf("\nOpening file foodmenu.csv failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nOpening file foodmenu.csv...");
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
    printf("\nClosing file foodmenu.csv...");
    fclose(filepointer);
}

int idgenarate(CustomerOrderInfo a[]){ // return an ID for the customer order(Running OK)
    FILE *filepointer;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        printf("\nidgenarate.txt failed to open");
        exit(EXIT_FAILURE);
    }
    else{
        printf("/nOpening idgenarate.txt...\n");
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
        printf("\nClosing idgenarate.txt...");
        fclose(filepointer);
    }
    else{
        i = atoi(temp);
        i = i + 1;
        printf("Writing mode activated.\n");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "w");
        fprintf(filepointer,"%d", i);
        printf("\nClosing idgenarate.txt...");
        fclose(filepointer);
    }
    return i;
}

int readHistoryID(){ // Read history ID store from file(Running Ok)
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
    printf("\nClosing idgenarate.txt...");
    fclose(filepointer);
    return i;
}

void uploadOnline(CustomerOrderInfo a[])
{
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if (filepointer == NULL){
        printf("\nError opening CSV file");
        backupData(a);
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nOpening CustomerOrderInfo.csv...");
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
    printf("\nClosing CustomerOrderInfo.csv");
    fclose(filepointer);
}

void uploadToFile(CustomerOrderInfo a[], const int count){ // used if there have something change to struct(Working Ok)
    int temp = count;
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "w");
    if(filepointer == NULL){
        printf("Error: Could not open CustomerOrderInfo.csv");
        backupData(a);
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nOpening CustomerOrderInfo.csv...");
    }

    int line = 0;
    fprintf(filepointer, "ID,UserName,Date,TableNumber,ChooseFood,Prizes\n");
    while(line <= temp){
        fprintf(filepointer,"%s,%s,%s,%s,%s,%s,%s\n", a[line].ID,a[line].userName,a[line].date,a[line].tableNumber,a[line].chooseFood,a[line].sum,"");
        line ++;
    }
    printf("\nClosing CustomerOrderInfo.csv...");
    fclose(filepointer);
}

void moveData(CustomerOrderInfo a[], CustomerOrderInfoInput b){ // move data from CustomerOrderInfoInput to CustomerOrderInfo (Working Ok)
    int i = atoi(b.ID);
    // -------------------------------Funcion work--------------------------------------------------
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
        printf("\nERROR: Failed to open CustomerOrderInfoBackup.csv");
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nOpening CustomerOrderInfoBackup.csv");
    }
    fprintf(filepointer, "ID,UserName,Date,TableNumber,ChooseFood,Prizes");
    int count = readHistoryID();
    int cout = 0;
    while(cout < count){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s\n",a[cout].ID,a[cout].userName,a[cout].date,a[cout].chooseFood,a[cout].sum," " );
        cout ++;
    }
    printf("\nClosing file CustomerOrderInfoBackup.csv...");
    fclose(filepointer);
}

int calculateSummary(CustomerOrderInfoInput a, FoodMenu b[],CustomerOrderInfo c[]){
    char buf[MAX],*temp;
    char contain1[MAX], contain2[MAX],contain3[MAX];
    int j = 0, k = 0;
    int foodOrderNumber = 0,quantity = 0;
    int foodPrizes = 0;
    int sum = 0;
    //------------------------------Funcion work---------------------------------------
    strcpy(buf,a.chooseFood);
    temp = strtok(buf, "/"); 
    strcpy(contain3, temp);
    for(int i = 0; i < strlen(temp); i++){
        if(contain3[i] != '.'){
            char temp2 = contain3[i];
            contain2[j] = contain3[i];
            j++;
            if(i == (strlen(temp) - 1)){
                quantity = atoi(contain2);
                sum = sum + (quantity * foodPrizes);
                foodPrizes = 0;
                quantity = 0;
                memset(contain2,0,sizeof(contain2));
                memset(contain3, 0 ,sizeof(contain3));
                j = 0;  
            }            
        }
        else{
            j = 0;
            foodOrderNumber = atoi(contain2);
            foodPrizes = atoi(b[foodOrderNumber - 1].prizes);
            memset(contain2,0,sizeof(contain2));
        }
    }
    temp = strtok(NULL, "/");
    while(temp != NULL){
        strcpy(contain3, temp);
        for(int i = 0; i < strlen(temp); i++){
            if(contain3[i] != '.'){
                char temp2 = contain3[i];
                contain2[j] = contain3[i];
                j++;
                if(i == (strlen(temp) - 1)){
                    quantity = atoi(contain2);
                    sum = sum + (quantity * foodPrizes);
                    foodPrizes = 0;
                    quantity = 0;
                    memset(contain2,0,sizeof(contain2));
                    memset(contain3,0,sizeof(contain3));
                    j = 0;  
                }            
             }
            else{
                j = 0;
                foodOrderNumber = atoi(contain2);
                foodPrizes = atoi(b[foodOrderNumber - 1].prizes);
                memset(contain2,0,sizeof(contain2));
            }
        }
        temp = strtok(NULL, "/");
    }
    sum = sum * atoi(a.tableNumber);
    char summarize[1080];
    sprintf(summarize, "%c" , sum);
    strcpy(a.sum,summarize);
    moveData(c, a);
    return sum;    
}

void customerInfoInput(char ID[], char userName[],char date[], char tableNumber[],char chooseFood[],char sum[],CustomerOrderInfoInput a){
    strcpy(a.ID,ID);
    strcpy(a.userName,userName);
    strcpy(a.date,date);
    strcpy(a.tableNumber,tableNumber);
    strcpy(a.chooseFood,chooseFood);
}










