#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1000

typedef struct{
    char ID[128];
    char userName[128];
    char tableNumber[3];
    char salmonQuantity[128];
    char friedRiceQuantity[128];
    char spaghettiQuantity[128];
    char musselQuantity[128];
    char phoBoQuantity[128];
    char pumpkinSoupQuantity[128];
    char saladQuantity[128];
    char applePieQuantity[128];
    char eggBenedictQuantity[128];
    char springRollQuantity[128];
    char grilledPorkQuantity[128];
    char beefSteakQuantity[128];
    char summarize[128];
}CustomerOrderInfo;

typedef struct {
    char ID[256];
    char guestName[256];
    char table[3];
}guestData;

typedef struct {
    char dishName[256];
    char dishPrice[256];
    int quantity;
}dishes;

int idGenerator(){
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
    printf("\nClosing idgenarate.txt...");
    fclose(filepointer);
    return i;
}

void backupDataBase(CustomerOrderInfo a[]){
    const int temp = readHistoryID();
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfoBackup.csv", "w");
    if (filepointer == NULL){
        printf("\nError: Could not open CustomerOrderInfoBackup.csv file");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Opening CustomerOrderInfoBackup.csv file");
    }
    int line = 0;
    fprintf(filepointer,"ID,UserName,TableNumber,Salmon,Fried Rice,Spaghetti,Mussel,Pho Bo,Pumpkin Soup,Salat,Apple Pie,Egg Benedict,Spring Roll,Grilled Pork,Beef Steak,Summarized\n");
    while(line <= temp){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
        a[line].ID,
        a[line].userName,
        a[line].tableNumber,
        a[line].salmonQuantity, 
        a[line].friedRiceQuantity,
        a[line].spaghettiQuantity,
        a[line].musselQuantity,
        a[line].phoBoQuantity,
        a[line].pumpkinSoupQuantity,
        a[line].saladQuantity,
        a[line].applePieQuantity,
        a[line].eggBenedictQuantity,
        a[line].springRollQuantity,
        a[line].grilledPorkQuantity,
        a[line].beefSteakQuantity,
        a[line].summarize
        );
        line ++;
    }
    printf("Closing file CustomerOrderInfoBackup.csv...");
    fclose(filepointer);
}

void uploadToFile(CustomerOrderInfo a[]){
    const int temp = readHistoryID();
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "w");
    if (filepointer == NULL){
        printf("\nERROR: Could not open file CustomerOrderInfo.csv");
        backupDataBase(a);
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nOpening CustomerOrderInfo.csv...");
    }
    int line = 0;
    fprintf(filepointer,"ID,UserName,TableNumber,Salmon,Fried Rice,Spaghetti,Mussel,Pho Bo,Pumpkin Soup,Salat,Apple Pie,Egg Benedict,Spring Roll,Grilled Pork,Beef Steak,Summarized\n");
    while (line <= temp){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
        a[line].ID,
        a[line].userName,
        a[line].tableNumber,
        a[line].salmonQuantity, 
        a[line].friedRiceQuantity,
        a[line].spaghettiQuantity,
        a[line].musselQuantity,
        a[line].phoBoQuantity,
        a[line].pumpkinSoupQuantity,
        a[line].saladQuantity,
        a[line].applePieQuantity,
        a[line].eggBenedictQuantity,
        a[line].springRollQuantity,
        a[line].grilledPorkQuantity,
        a[line].beefSteakQuantity,
        a[line].summarize,
        ""
        );
        line ++;
    }
    printf("\nClosing CustomerOrderInfo.csv file...");
    fclose(filepointer);
}

void uploadCustomerOrderData(CustomerOrderInfo a[]){
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if (filepointer == NULL){
        printf("\nError opening CSV file");
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
        strcpy(a[i].tableNumber, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].salmonQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].friedRiceQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].spaghettiQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].musselQuantity, temp);
        
        temp = strtok(NULL, ",");
        strcpy(a[i].phoBoQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].pumpkinSoupQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].saladQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].applePieQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].eggBenedictQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].springRollQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].grilledPorkQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].beefSteakQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].summarize, temp);
        i++;
    }
    printf("\nClosing CustomerOrderInfo.csv");
    fclose(filepointer);
}

void moveData(guestData a, dishes b[],CustomerOrderInfo c[],int sum){ 
    int i = atoi(a.ID);
    strcpy(c[i].ID,a.ID );
    strcpy(c[i].userName, a.guestName);
    strcpy(c[i].tableNumber, a.table);
    strcpy(c[i].salmonQuantity, b[1].dishPrice);
    strcpy(c[i].friedRiceQuantity,b[2].dishPrice);
    strcpy(c[i].spaghettiQuantity, b[3].dishPrice);
    strcpy(c[i].musselQuantity, b[4].dishPrice);
    strcpy(c[i].phoBoQuantity, b[5].dishPrice);
    strcpy(c[i].pumpkinSoupQuantity, b[6].dishPrice);
    strcpy(c[i].saladQuantity,b[7].dishPrice);
    strcpy(c[i].applePieQuantity,b[8].dishPrice);
    strcpy(c[i].eggBenedictQuantity,b[9].dishPrice);
    strcpy(c[i].springRollQuantity,b[10].dishPrice);
    strcpy(c[i].grilledPorkQuantity,b[11].dishPrice);
    strcpy(c[i].beefSteakQuantity,b[12].dishPrice);
    char summarize[128];
    sprintf(summarize,"%c",sum);
    strcpy(c[i].summarize,summarize);
    printf("Move data success !!!");
    uploadToFile(c);
    printf("Upload to file success !!!");
}

int calculateSummary(dishes a[],CustomerOrderInfo b[],guestData c){
    int sum = 0;
    int summarize = 0;
    char temp[128];
    for (int i = 1; i < 13; i++){
        for(int j = 0; j < strlen(a[i].dishPrice); i++){
            if(isdigit(a[i].dishPrice[j]) == 0){
                temp[j] = a[i].dishPrice[j];
            }
            else{
                sum = sum + (atoi(temp) * a[i].quantity);
                break;
            }
        }
    }
    moveData(c,a,b,sum);
    return sum;
}

int totalRevenue(CustomerOrderInfo a[]){
    int sum = 0;
    for (int i = 0; i < readHistoryID(); i++){
        sum = sum + atoi(a[i].summarize);
    }
    return sum;
}

int totalDishOrdered(CustomerOrderInfo a[]){
    int total = 0;
    for(int i = 0; i < readHistoryID(); i++){
        total = total + atoi(a[i].salmonQuantity) + atoi(a[i].friedRiceQuantity) + atoi(a[i].spaghettiQuantity) + atoi(a[i].musselQuantity) + atoi(a[i].phoBoQuantity) + atoi(a[i].pumpkinSoupQuantity) + atoi(a[i].saladQuantity) + atoi(a[i].applePieQuantity) + atoi(a[i].eggBenedictQuantity) + atoi(a[i].springRollQuantity) + atoi(a[i].grilledPorkQuantity) + atoi(a[i].beefSteakQuantity);
    }
    return total;
}

int totalCustomer(){
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

int main(){



    return 0;
}