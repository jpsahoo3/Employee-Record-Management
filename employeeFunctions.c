char empname[40];
char another[10];
FILE *fp, *ft; 
void addRecord() {
struct Employee e;
    fseek(fp, 0, SEEK_END); /// search the file and move cursor to end of the file
    /// here 0 indicates moving 0 distance from the end of the file
    strcpy(another, "y");
    while (strcmp(another, "y") == 0) /// if user want to add another record
    {
        printf("Enter name: ");
        scanf("%s", e.name);
        printf("Enter age: ");
        scanf("%d", &e.age);
        printf("Enter basic salary: ");
        scanf("%f", &e.basicSalary);
        fwrite(&e,sizeof(e),1,fp);
        updateTextFile();
        printf("Employee details saved successfully.");
        printf("\nAdd another record(y/n): ");
        scanf("%s", another);
    }
}

void updateTextFile() {
struct Employee e;
    rewind(fp);
    FILE *recordFP;
    recordFP = fopen("employeeData.txt", "w+");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        fprintf(recordFP,"%s%15d%15.2f\n",e.name,e.age,e.basicSalary);
    }
    fclose(recordFP);
}



void displayRecord() {
    struct Employee e;
    rewind(fp);
    printf("%s\t%s\t%s\n", "Name", "Age", "Basic Salary");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        printf("%s\t%d\t%.2f\n",e.name,e.age,e.basicSalary);
    }
}

void modifyRecord() {
struct Employee e;
    strcpy(another, "y");
    while (strcmp(another, "y") == 0) {
        printf("Enter the employee name to modify: ");
        scanf("%s", empname);
        rewind(fp);
        int isEmpFound = 0;
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.name,empname)==0){
                isEmpFound++;
                printf("Enter new name:");
                scanf("%s",e.name);
                printf("Enter new age:");
                scanf("%d",&e.age);
                printf("Enter basic salary:");
                scanf("%f",&e.basicSalary);
                fseek(fp,-sizeof(e),SEEK_CUR);
                fwrite(&e,sizeof(e),1,fp);
                updateTextFile();
                printf("Employee details are modified");
                break;
            }
            
        }
        if(isEmpFound == 0) {
            printf("Employee details not found.");
        }
        printf("\nModify another record(y/n): ");
        scanf("%s", another);
    }
}

void deleteRecord() {
struct Employee e;
    strcpy(another, "y");
    while (strcmp(another, "y") == 0) {
        printf("\nEnter name of employee to delete: ");
        scanf("%s", empname);
        int isEmployeeFound = 0;
        ft = fopen("Temp.dat", "wb"); /// create a intermediate file for temporary storage
        rewind(fp);
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.name,empname)!=0){
                fwrite(&e,sizeof(e),1,ft);
            }
            else
                isEmployeeFound++;
        }
        fclose(fp);
        fclose(ft);
        remove("EMP.DAT");
        rename("Temp.dat","EMP.DAT");
        fp = fopen("EMP.DAT", "rb+");
        if(isEmployeeFound == 0) {
            printf("Employee details not found.");
        } else {
            printf("Employee details deleted.");
        }
        updateTextFile();
        printf("\nDelete another record(y/n): ");
        
        scanf("%s", another);
    }
}
