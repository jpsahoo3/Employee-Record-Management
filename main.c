#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "employeeHeader.h"
#include "employeeFunctions.c"

int choice;

int main() {
    fp = fopen("employeeData.txt", "a");
    fp = fopen("EMP.DAT", "a");
    fp = fopen("employeeData.txt", "a");
    ft = fopen("Temp.dat", "a");
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("The file doesn't exists");
            exit(1);
        }
    }
    while (1) {
        printf("\n1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Modify Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecord();
                break;

            case 3:
                modifyRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid Input!");
        }
    }
    return 0;
}

