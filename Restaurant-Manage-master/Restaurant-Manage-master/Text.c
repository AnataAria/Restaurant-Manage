#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 1000

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

int caculateSummary(CustomerOrderInfoInput a, FoodMenu b[],CustomerOrderInfo c[]){
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
    return sum;    
}


int main(){
    CustomerOrderInfo a[1000];
    CustomerOrderInfoInput b;
    FoodMenu c[MAX];
    strcpy(b.ID, "0");
    strcpy(b.userName, "NQV");
    strcpy(b.date, "9/6/2003");
    strcpy(b.tableNumber,"2");
    strcpy(b.chooseFood, "1.8/9.2");
    strcpy(b.sum, "100000");
    foodMenuUpload(c);
    printf("%d",caculateSummary(b,c,a));
    
    return 0;
}