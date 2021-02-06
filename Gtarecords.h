//
// Created by Nupur Adhvaryu on 7/20/2020.
//

#ifndef NUPURADHVARYUASSIGN3_GTARECORDS_H
#define NUPURADHVARYUASSIGN3_GTARECORDS_H
#define RANGE 100

typedef struct records{
    char regions[20];
    char towns[20];
    char races[20];
    int numberofpeople;
    int yearlyincome;
    struct records *next;
}recordNode,*recordPtr;

void addRecord(recordPtr* toprec, char region[20], char town[20], char race[20], int numpeople, int income);
void deleteRecord(recordPtr* toprec , char region[20], char town[20], char race[20], int numpeople, int income);
recordPtr generate();
void showAllRecords(recordPtr toprec);
void readDataToConsole(char fname[20]);
void addDataToFile(recordPtr* toprec, char fname[20]);
void displayRegion(recordPtr toprec);
void displayTown(recordPtr toprec);
void displayRace(recordPtr toprec);
void displayFamilySize(recordPtr toprec);
void displayIncome(recordPtr toprec);
void displayPairedTown(recordPtr toprec);
void displayPairedFamilySize(recordPtr toprec);
void displayPairedIncome(recordPtr toprec);
void addNewRecord(recordPtr* toprec);
void deleteByRace(recordPtr* toprec);
void deleteByFamilySize(recordPtr* toprec);


#endif //NUPURADHVARYUASSIGN3_GTARECORDS_H