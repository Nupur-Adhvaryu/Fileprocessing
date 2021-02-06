//
// Created by Nupur Adhvaryu on 7/20/2020.
//
// Nupur Adhvaryu (991518688)

#include <stdio.h>
#include <stdlib.h>
#include "Gtarecords.h"
#include <string.h>
#include <time.h>

char r[3][20] ={"Peel", "York", "Durham"};
char t[6][20] = {"Brampton", "Mississauga", "Maple","Vaughan","Whitby", "Oshawa"};
char ra[5][20] = {"Caucasian", "Indigenous", "AfricanAmerican", "Asian", "Other"};


//helps is adding the record in a data
void addRecord(recordPtr* toprec, char region[20], char town[20], char race[20], int numpeople, int income) {
    recordNode* ptr = malloc(sizeof(recordNode));
    strcpy(ptr->regions ,region);
    strcpy(ptr->towns, town);
    strcpy(ptr->races, race);
    ptr->numberofpeople = numpeople;
    ptr->yearlyincome = income;
    ptr->next = *toprec;
    *toprec = ptr;
}

//helps in deleting record from the data
void deleteRecord(recordPtr* toprec, char region[20], char town[20], char race[20], int numpeople, int income) {
    recordNode *temp = *toprec;
    *toprec = (*toprec)->next;
    free(temp);
}

//shows all the data of records
void showAllRecords(recordPtr toprec) {
    recordPtr p = toprec;

    while (p != NULL) {
        printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
        p = p->next;
    }
}

//generates the records through a loop of 100
recordPtr generate(){

     recordPtr to = malloc(sizeof(recordNode));
    srand(time(NULL));

     int a = (int)(rand() % 3);
     int b = (int)(rand() % 2) +2*a;
     int c = (int)(rand() % 5) ;
     int d = (int)(rand() % 50000 +50000);
     int e = (int)(rand() % 6 + 2);

     strcpy(to->regions, r[a]);
     strcpy(to->towns, t[b]);
     strcpy(to->races, ra[c]);
     to->numberofpeople = e;
     to->yearlyincome = d;
     int i = 0;

    while (1){
       // recordNode* pt = malloc(sizeof(*pt));
       int j;
         a = (int)(rand() % 3);
         b = (int)(rand() % 2 ) +2*a;
         c = (int)(rand() % 5) ;
         d = (int)(rand() % 50000 +50000);
         e = (int)(rand() % 6 + 2);

        addRecord(&to, r[a], t[b], ra[c], e,d);
        i++;
        if(i>100) {
            break;
        }

    }
    return to;

}

//Adds data to the file
void addDataToFile(recordPtr* toprec, char fname[20]){
    FILE *data;
    if((data = fopen(fname,"w"))==NULL){
        puts("File Cannot Open...");
        exit(10);
    }
    else{
        recordPtr p = *toprec;
        while (p!=NULL){
            fprintf(data,"%s\t%s\t%s\t%d\t%d\n",p->regions,p->towns,p->races,p->numberofpeople,p->yearlyincome);
            p = p->next;
        }
    }
    fclose(data);
}

//Fetches data from the file to the console
void readDataToConsole(char fname[20]){
    FILE *data;
    if((data = fopen(fname,"r"))==NULL){
        puts("File Cannot Open...");
        exit(10);
    } else{
        char rec[150];
        while(fgets(rec,150,data)!=NULL){
            char* tok = strtok(rec,"||");
            while(tok){
                printf("%s",tok);
                tok = strtok(NULL,"||");
            }
        }
    }
    fclose(data);
}

// Displays the records with opting desired region
void displayRegion(recordPtr toprec){
    int regId;
    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&regId);

    if(regId>=0&&regId<=2){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->regions,r[regId]) ==0){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry : 0 or 1 or 2\n");
    }

}

//displays records with opting desired town
void displayTown(recordPtr toprec){
    int townId;
    for(int i = 0;i<6;i++){
        printf("%d. %s\n",i,t[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&townId);

    if(townId >= 0 && townId <= 5){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->towns,t[townId]) == 0){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry : 0 to 5\n");
    }

}

//displays records with opting desired race
void displayRace(recordPtr toprec){
    int raceId;
    for(int i = 0;i<5;i++){
        printf("%d. %s\n",i,ra[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&raceId);

    if(raceId >= 0 && raceId <= 4){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->races,ra[raceId]) == 0){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry : 0 to 4\n");
    }
}

//displays records with opting desired family size
void displayFamilySize(recordPtr toprec){
    int members;
    printf("Enter Number of Family Members.");
    scanf("%d",&members);
    if(members>=2&&members<=8){
        recordPtr p = toprec;
        while (p != NULL) {
            if(p->numberofpeople<=members){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid family size : 2 to 8\n");
    }

}

//displays data with opting desired yearly income
void displayIncome(recordPtr toprec){
    int income,choice;
    printf("Enter Number of Family Members.");
    scanf("%d",&income);
    printf("Do You want greater than(1) or less than(2) this amount.");
    scanf("%d",&choice);
    recordPtr p = toprec;
    while (p != NULL) {
        if(choice==1) {
            if (p->yearlyincome > income) {
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople,
                       p->yearlyincome);
            }
        }
        else{
            if (p->yearlyincome <= income) {
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople,
                       p->yearlyincome);
            }
        }
        p = p->next;
    }
}

//displays data of desired region and town pair
void displayPairedTown(recordPtr toprec){
    int regId, townId;
    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Region Selection :");
    scanf("%d",&regId);
    for(int i = 0;i<6;i++){
        printf("%d. %s\n",i,t[i]);
    }
    printf("Enter Your Town Selection :");
    scanf("%d",&townId);

    if(regId>=0 &&regId<=2 && townId >= 0 && townId <= 5){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->regions,r[regId]) ==0&& strcmp(p->towns,t[townId]) == 0){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry..\n");
    }

}

//displays data of desired region and family size
void displayPairedFamilySize(recordPtr toprec){
    int regId, members;
    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Region Selection :");
    scanf("%d",&regId);
    printf("Enter Number of Family Members.");
    scanf("%d",&members);

    if(regId>=0&&regId<=2&&members>=2&&members<=8){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->regions,r[regId]) ==0&&p->numberofpeople<=members){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry..\n");
    }

}

//displays data of desired region and income pair
void displayPairedIncome(recordPtr toprec){
    int regId, income;
    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Region Selection :");
    scanf("%d",&regId);
    printf("Enter house hold income.");
    scanf("%d",&income);

    if(regId>=0&&regId<=2){
        recordPtr p = toprec;
        while (p != NULL) {
            if(strcmp(p->regions,r[regId]) ==0&&p->yearlyincome <= income){
                printf("%s \t %s\t %s\t %d \t %d \n", p->regions, p->towns, p->races, p->numberofpeople, p->yearlyincome);
            }
            p = p->next;
        }
    }
    else{
        printf("please enter a valid entry..\n");
    }
}

//adds a new record to the data
void addNewRecord(recordPtr* toprec){
    int regId,townId,raceId,members,income;

    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&regId);
    for(int i = 2*regId;i<2*regId+2;i++){
        printf("%d. %s\n",i,t[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&townId);
    for(int i = 0;i<5;i++){
        printf("%d. %s\n",i,ra[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&raceId);
    printf("Enter Number of Family Members.");
    scanf("%d",&members);
    printf("Enter HouseHold Income.");
    scanf("%d",&income);
    addRecord(toprec,r[regId],t[townId],r[raceId],members,income);
}

//displays the record of desired region, town and race
void deleteByRace(recordPtr* toprec){
    int regId, townId, raceId;
    for(int i = 0;i<3;i++){
        printf("%d. %s\n",i,r[i]);
    }
    printf("Enter Your Region Selection :");
    scanf("%d",&regId);
    for(int i = 0;i<6;i++){
        printf("%d. %s\n",i,t[i]);
    }
    printf("Enter Your Town Selection :");
    scanf("%d",&townId);

    for(int i = 0;i<5;i++){
        printf("%d. %s\n",i,ra[i]);
    }
    printf("Enter Your Selection :");
    scanf("%d",&raceId);

    if(regId>=0 && regId<=2 && townId >= 0 && townId <= 5 && 0<=raceId && raceId<=5){

        recordPtr p = *toprec;
        while((*toprec)->next->next != NULL){

            recordNode *temp = (*toprec)->next;
            (*toprec)->next = (*toprec)->next->next;
            free(temp);
        }
    }
    else{
        printf("please enter a valid entry..\n");
    }
}

//deletes the record of desired region, town and family size triplet
void deleteByFamilySize(recordPtr* toprec) {
    int regId, townId, members;
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i, r[i]);
    }
    printf("Enter Your Region Selection :");
    scanf("%d", &regId);
    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i, t[i]);
    }
    printf("Enter Your Town Selection :");
    scanf("%d", &townId);

    printf("Enter Number of Family Members.");
    scanf("%d", &members);

        if (regId >= 0 && regId <= 2 && townId >= 0 && townId <= 5 && 2 <= members && members <= 8) {

            recordPtr p = *toprec;
            while ((*toprec)->next->next != NULL) {

                recordNode *temp = (*toprec)->next;
                (*toprec)->next = (*toprec)->next->next;
                free(temp);
            }
        } else {
            printf("please enter a valid entry..\n");
        }



}