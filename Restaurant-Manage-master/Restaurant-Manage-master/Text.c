#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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

void caculateSummary(){
    char buf[MAX],*temp;
    char contain1[MAX], contain2[MAX],contain3[MAX];
    int j = 0, k = 0;
    int foodOrderNumber = 0;
    int quantity = 0;
    bool stage = true;
    strcpy(buf,"10.20/3.2/9.6");
    temp = strtok(buf, "/"); 
    strcpy(contain3, temp);
    for(int i = 0; i < strlen(temp); i++){
        if(contain3[i] != '.'){
            char temp2 = contain3[i];
            contain2[j] = contain3[i];
            j++;
            if(i == (strlen(temp) - 1)){
                quantity = atoi(contain2);
                memset(contain2,0,sizeof(contain2));
                memset(contain3, 0 ,sizeof(contain3));
                j = 0;  
            }            
        }
        else{
            j = 0;
            foodOrderNumber = atoi(contain2);
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
                    strcpy(contain2,"");
                    strcpy(contain3,"");
                    j = 0;  
                }            
             }
            else{
                j = 0;
                foodOrderNumber = atoi(contain2);
                strcpy(contain2,"");
            }
        }
        temp = strtok(NULL, "/");
    }
    
}

int main(){
    caculateSummary();
    return 0;
}