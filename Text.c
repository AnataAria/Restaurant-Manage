#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

typedef struct{
    char ID[10000];
    char userName[256];
    char date[256];
    char tablenumber[256];
    char choosefood[256];
    char sum[MAX];
}CustomerOrderInfo;

int main(){
    CustomerOrderInfo a[MAX];
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if(filepointer == NULL){
        printf("ERROR: Could not open");
        exit(-1);
    }
    else{
        printf("Opening...");
    }
    int i = 0;
    char buf[MAX], *tmp;
    while(fgets(buf,sizeof(buf),filepointer) != NULL){
        tmp = strtok(buf, ",");
        strcpy(a[i].ID, tmp);

        tmp = strtok(NULL, ",");
        strcpy(a[i].userName, tmp);

        tmp = strtok(NULL, ",");
        strcpy(a[i].date, tmp);

        tmp = strtok(NULL, ",");
        strcpy(a[i].tablenumber, tmp);

        tmp = strtok(NULL, ",");
        strcpy(a[i].choosefood, tmp);

        i++;
    }
}