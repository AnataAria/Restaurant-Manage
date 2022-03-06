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

CustomerOrderInfoInput input(){
    CustomerOrderInfoInput a;
        strcpy(a.chooseFood,"2.1/1.2");
    return a;
}

void caculateSummary(){
    char buf[1028],contain1[1028], contain2[1028],*temp1,*temp2,*temp3;
    int i = 0;
    int j = 0;
    bool stage = true;
    int type = 0;
    int quantity = 0;
    int prizes;
    int sum;
    strcpy(buf,"1.1/2.2/5.5/6.2");
    temp1 = strtok(buf,"/");
    while(i < strlen(temp1)){
        if (stage == true){
            strcat(contain1,*(temp1 + i));
            if(isdigit(*(temp1 + i + 1))){
                stage = true;
            }
            else{
                stage = false;
            }
        }
        else{
            j++;
        }
        switch(j){
            case 1:
                type = atoi(contain1);
                break;
            case 2:
                quantity = atoi(contain1);
                j = 0;
                break;
        }       
        i++;
    }
}

int main(){
    caculateSummary();
    return 0;
}