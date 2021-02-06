//
// Created by Nupur Adhvaryu on 7/20/2020
//

#include <stdio.h>
#include "Gtarecords.h"

 int main(){
    recordPtr top = generate();
    printf("\n");

    //the text file in which all the data of records will be stored
    char filename[20]="..//GTArecords.txt";

    while(1){
        //All these conditions provides options to edit the data of show it
        int j;
        printf("1.  Display household records of GTA of only Region. \n");
        printf("2.  Display household records of GTA of only Town. \n");
        printf("3.  Display household records of GTA of only Race. \n");
        printf("4.  Display household records of GTA of only Family member size. \n");
        printf("5.  Display household records of GTA of only the income. \n");
        printf("6.  Display household records of GTA of pair of Region and Town. \n");
        printf("7.  Display household records of GTA of pair Region and Family member size. \n");
        printf("8.  Display household records of GTA of pair Region and maximum income. \n");
        printf("9.  Add a new record.\n");
        printf("10. Delete a record according to Region, Town and Race triplet. \n");
        printf("11. Delete a record according to Region, Town and Family size triplet. \n");
        printf("12. Display the updated version of file.\n");
        printf("13. Store data to the file.\n");
        printf("14. Display the data from the file. \n");
        printf("15. Exit the program.\n");
        scanf("%d", &j);
        if(j == 1){
            displayRegion(top);
        } else if(j == 2) {
            displayTown(top);
        } else if (j == 3){
            displayRace(top);
        } else if(j == 4){
            displayFamilySize(top);
        } else if(j == 5){
            displayIncome(top);
        }else if(j == 6){
            displayPairedTown(top);
        }else if(j == 7){
            displayPairedFamilySize(top);
        }else if(j == 8){
            displayPairedIncome(top);
        } else if(j==9){
            addNewRecord(&top);
        } else if(j == 10){
            deleteByRace(&top);
        } else if(j == 11){
            deleteByFamilySize(&top);
        } else if(j == 12){
            readDataToConsole(filename);
        } else if(j == 13){
            addDataToFile(&top,filename);
        }else if(j == 14){
            showAllRecords(top);
        }
        else {
            break;
        }
    }

    return 0;
}