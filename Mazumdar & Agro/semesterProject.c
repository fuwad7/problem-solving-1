#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//GLOBAL DEFINITION SECTION

void mainMenu();
int authentication();

// functions to manage projects
void projectMenu();
void addNewProject();
void saveProjectInfo();
void viewAllProjects();
void updateProjectInfo();
void deleteProjectInfo();

// functions to manage expenses
void expenseMenu();
void addNewExpense();
void saveExpenseInfo();
void viewAllExpenses();
void updateExpenseInfo();
void deleteExpenseInfo();

// functions to manage feeding history
void feedHistoryMenu();
void addNewfeedHistory();
void savefeedHistoryInfo();
void viewAllfeedHistory();
void updatefeedHistoryInfo();
void deletefeedHistoryInfo();

// functions to manage Staff
void StaffMenu();
void addNewStaff();
void saveStaffInfo();
void viewAllStaff();
void updateStaffInfo();
void deleteStaffInfo();

// functions to manage sells
void sellsMenu();
void addNewSells();
void saveSellsInfo();
void viewAllSells();
void updateSellsInfo();
void deleteSellsInfo();

// functions to generate reports
void generateReport();
// functions for price estimation
void priceEstimate();


//Project structure
struct Project{
    int id;
    float estimatedBudget;
    char projectName[50], projectShortDes[100], projectType[30], startDate[15], endDate[15];
};

//Expense structure
struct Expense{
    int id, projectId;
    float amount;
    char date[30], productOrService[20], supplierInfo[25];
};

//FeedingHistory structure
struct FeedingHistory{
    int id, projectId;
    float quantity;
    char date[10], time[10], foodCategory[10];
};

//Staff structure
struct Staff{
    int id, phoneNumber;
    float salary;
    char name[50], address[50], email[25];
};

//SellsInfo structure
struct SellsInfo{
    int id, projectId;
    float amount, quantity;
    char productName[20],date[10];
};


// declaring file pointer for the file read write operation
FILE *fileToOperate;
// declaring a variable to hold data of our custom data structure
struct Project projectInfo;
struct Expense expenseInfo;
struct FeedingHistory feedHistoryInfo;
struct Staff StaffInfo;
struct SellsInfo sellsInfo;

//main function of the program
int main(){
    system("cls");
    int choice;
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2");
    printf("\n\xDB\xDB\xDB\xDB\xB2 \t\t\tAdmin Panel  \n\xDB\xDB\xDB\xDB\xB2 1. Enter Username   \n\xDB\xDB\xDB\xDB\xB2 2. Exit\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\nPlease enter your choice (1/2) : ");
    login: scanf("%d", &choice);
    if(choice==1){
        //calling the login function to check whether password is correct or not
        reauthenticate: if(authentication()==0){
            mainMenu();
        }else {
            printf("\nYour password or Username is incorrect. Please Try again.\n");
            goto reauthenticate; // taking re-input for the valid password
        }
    }else if(choice==2){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }else{
        printf("\nInvalid Choice. You should enter \"1\" for Login or \"2\" for Exit.\n\nPlease enter your choice again (1/2) : ");
        goto login;
    }
    return 0;

}

// main menu of the project
void mainMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2");
    printf(" \n\xDB\xDB\xDB\xDB\xB2 1. Manage Projects"
            "\n\xDB\xDB\xDB\xDB\xB2 2. Manage Expenses"
            "\n\xDB\xDB\xDB\xDB\xB2 3. Manage Feeding History"
            "\n\xDB\xDB\xDB\xDB\xB2 4. Manage Staff"
            "\n\xDB\xDB\xDB\xDB\xB2 5. Manage Sells"
            "\n\xDB\xDB\xDB\xDB\xB2 6. Generate Report"
            "\n\xDB\xDB\xDB\xDB\xB2 7. Price Estimation"
            "\n\xDB\xDB\xDB\xDB\xB2 8. Signout\n");
    printf("\xDB\xDB\xDB\xDB\xB2");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\nEnter Your Choice (1/2/3/4/5/6/7/8) : ");

    int userChoice;
    redirToMainMenu: scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
        projectMenu();
        break;
    case 2:
        expenseMenu();
        break;
    case 3:
        feedHistoryMenu();
        break;
    case 4:
        StaffMenu();
        break;
    case 5:
        sellsMenu();
        break;
    case 6:
        generateReport();
        break;
    case 7:
        priceEstimate();
        break;
    case 8:
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
        break;
    default:
        printf("\nInvalid input. Please enter a valid input : ");
        goto redirToMainMenu;
    }

}

// necessary codes for password protected login
int authentication(){
    char fixPassword[15]="12345";
    char fixUsername[15]="fuwad";
    char userPassword[15],userName[15];

    printf("\nEnter Username : ");
    fflush(stdin);
    gets(userName);
    printf("\nEnter Password : ");
    fflush(stdin);
    gets(userPassword);

    int flag = (strcmp(userPassword, fixPassword)) && (strcmp(userName,fixUsername));

    return flag;
}

// Functions of project management starts here
// project sub menu
void projectMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2 A. Create New Project Info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 B. View all project info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 C. Update existing project info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 D. Delete a project info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 E. Back to Main Menu\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    returnToProjectMenu: printf("\nChoose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewProject();
        break;
    case 'B':
        viewAllProjects();
        break;
    case 'C':
        updateProjectInfo();
        break;
    case 'D':
        deleteProjectInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToProjectMenu;
    }
}

void addNewProject(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(projectInfo.projectType);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &projectInfo.id);
    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(projectInfo.projectName);
    printf("Please Provide Short Details About Project: ");
    fflush(stdin);
    gets(projectInfo.projectShortDes);
    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(projectInfo.startDate);
    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(projectInfo.endDate);
    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%f", &projectInfo.estimatedBudget);

    saveProjectInfo();

    redirAddSub: printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t2.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        addNewProject();
    }else if (choice==2){
        projectMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirAddSub;
    }
}

void saveProjectInfo()
{
    fileToOperate = fopen("projectData.txt", "a");
    fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// codes to show the stored projects info from file
void viewAllProjects()
{
    system("cls");
    fileToOperate = fopen("projectData.txt", "r");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PROJECTS LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("  **Project ID**  \t\t**Project Title** \t**Start Date** \t\t**End Date**");
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        printf("\n\t%d\t\t\t%s\t\t%s\t\t%s\n",projectInfo.id,projectInfo.projectName, projectInfo.startDate,projectInfo.endDate);
    }
    fclose(fileToOperate);

    redirViewSub: printf("\n\n\t\t\t\t1. Project Menu\n\t\t\t\t2. Main Menu\n\t\t\t\t3. Signout");
    printf("\n\n\t\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        projectMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirViewSub;
    }
}

//codes to update the information of a specific project in a file
void updateProjectInfo(){
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int pId;
    fflush(stdin);
    scanf("%d", &pId);
    fileToOperate = fopen("projectData.txt", "r+");
    int found = 0;
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id == pId)
        {
            found = 1;
            printf("\nProvide all necessary information about the project\n\n");
            printf("Please Enter Project Type (Fish/Poultry): ");
            fflush(stdin);
            gets(projectInfo.projectType);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &projectInfo.id);
            printf("Please Enter Project Name/Title: ");
            fflush(stdin);
            gets(projectInfo.projectName);
            printf("Please Provide Short Details About Project: ");
            fflush(stdin);
            gets(projectInfo.projectShortDes);
            printf("Please Enter Project Start Date: ");
            fflush(stdin);
            gets(projectInfo.startDate);
            printf("Please Enter Project End Date: ");
            fflush(stdin);
            gets(projectInfo.endDate);
            printf("Please Enter the Estimated Budget: ");
            fflush(stdin);
            scanf("%f", &projectInfo.estimatedBudget);
            fseek(fileToOperate, -sizeof(projectInfo), SEEK_CUR);
            fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nProject information updated\n");
    }
    else
    {
        printf("\nProject with the given IID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// deleting a project info from the file
void deleteProjectInfo(){
    FILE  *removeFile;

    int pId;
    printf("Enter The project id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("projectData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id != pId)
        {
            fwrite(&projectInfo, sizeof(struct Project), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("projectData.txt");
    rename("temp.txt", "projectData.txt");

    printf("\nProject Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another  Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// Functions of project management end here

// Functions of expense management starts here

// expense menu function
void expenseMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2 A. Add an Expense\n");
    printf("\xDB\xDB\xDB\xDB\xB2 B. View all Expenses\n");
    printf("\xDB\xDB\xDB\xDB\xB2 C. Update existing expense info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 D. Delete a expense\n");
    printf("\xDB\xDB\xDB\xDB\xB2 E. Back to Main Menu\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    returnToExpenseMenu: printf("\nChoose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewExpense();
        break;
    case 'B':
        viewAllExpenses();
        break;
    case 'C':
        updateExpenseInfo();
        break;
    case 'D':
        deleteExpenseInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToExpenseMenu;
    }
}

// add new expense info function
void addNewExpense(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Expense ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.projectId);
    printf("Please Enter Product/Service Type: ");
    fflush(stdin);
    gets(expenseInfo.productOrService);
    printf("Please Enter Supplier Info: ");
    fflush(stdin);
    gets(expenseInfo.supplierInfo);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(expenseInfo.date);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &expenseInfo.amount);

    saveExpenseInfo();

    redirToSubMenu: printf("\n\t\t\t1. Do You Want To Add Another new Expense info?\n\t\t\t2. Expense Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewExpense();
    }else if (choice==2){
        expenseMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save expense info function
void saveExpenseInfo()
{
    fileToOperate = fopen("expenseData.txt", "a");
    fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllExpenses(){
    system("cls");

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL Expense LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf(" ***Expense ID*** \t***Project ID*** \t***Product/Service*** \t\t***Amount(BDT)*** \t***Date***");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%s\t\t%.2f\t\t\t%s\n",expenseInfo.id,expenseInfo.projectId,expenseInfo.productOrService, expenseInfo.amount,expenseInfo.date);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t\t1. Expense Menu\n\t\t\t\t2. Main Menu\n\t\t\t\t3. Signout");
    printf("\n\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        expenseMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update expense info function
void updateExpenseInfo(){
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int eId;
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("expenseData.txt", "r+");
    int found = 0;
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Expense ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.projectId);
            printf("Please Enter Product/Service Type: ");
            fflush(stdin);
            gets(expenseInfo.productOrService);
            printf("Please Enter Supplier Info: ");
            fflush(stdin);
            gets(expenseInfo.supplierInfo);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(expenseInfo.date);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &expenseInfo.amount);

            fseek(fileToOperate, -sizeof(expenseInfo), SEEK_CUR);
            fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nExpense information updated\n");
    }
    else
    {
        printf("\nExpense with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updatefeedHistoryInfo();
    }else if (choice==2){
        feedHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete expense info function
void deleteExpenseInfo(){
    FILE  *removeFile;

    int pId;
    printf("Enter The Expense Id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("expenseData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id != pId)
        {
            fwrite(&expenseInfo, sizeof(struct Expense), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("expenseData.txt");
    rename("temp.txt", "expenseData.txt");
    system("cls");
    printf("\nExpense Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteExpenseInfo();
    }else if (choice==2){
        expenseMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// functions of expense management ends here

// functions of feeding history management starts here
// feedHistory menu function
void feedHistoryMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2 A. Add a Feeding History\n");
    printf("\xDB\xDB\xDB\xDB\xB2 B. View all Feeding History\n");
    printf("\xDB\xDB\xDB\xDB\xB2 C. Update a Feeding History info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 D. Delete a Feeding History\n");
    printf("\xDB\xDB\xDB\xDB\xB2 E. Back to Main Menu\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    returnTofeedHistoryMenu: printf("\nChoose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewfeedHistory();
        break;
    case 'B':
        viewAllfeedHistory();
        break;
    case 'C':
        updatefeedHistoryInfo();
        break;
    case 'D':
        deletefeedHistoryInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnTofeedHistoryMenu;
    }
}

// add new feedHistory info function
void addNewfeedHistory(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Feeding History ID: ");
    fflush(stdin);
    scanf("%d", &feedHistoryInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &feedHistoryInfo.projectId);
    printf("Please Enter Quantity(KG): ");
    fflush(stdin);
    scanf("%f", &feedHistoryInfo.quantity);
    printf("Please Enter Food Category: ");
    fflush(stdin);
    gets(feedHistoryInfo.foodCategory);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(feedHistoryInfo.date);
    printf("Please Enter Time: ");
    fflush(stdin);
    gets(feedHistoryInfo.time);

    savefeedHistoryInfo();

    redirToSubMenu: printf("\n\t\t\t1.Do You Want To Add Another new Feeding History info?\n\t\t\t2.Feeding History Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewfeedHistory();
    }else if (choice==2){
        feedHistoryMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save feedHistory info function
void savefeedHistoryInfo()
{
    fileToOperate = fopen("feedHistoryData.txt", "a");
    fwrite(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllfeedHistory(){
    system("cls");
     printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL FEEDING HISTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf(" ***Feeding History ID*** ***Project ID*** ***Quantity*** \t***Food Category*** \t ***Date***");

    fileToOperate = fopen("feedHistoryData.txt", "r");
    while (fread(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%.2f\t\t\t%s\t\t%s\n",feedHistoryInfo.id,feedHistoryInfo.projectId,feedHistoryInfo.quantity, feedHistoryInfo.foodCategory,feedHistoryInfo.date);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t\t1. Feeding History Menu\n\t\t\t\t2. Main Menu\n\t\t\t\t3. Signout");
    printf("\n\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        feedHistoryMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update feedHistory info function
void updatefeedHistoryInfo(){
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int fhId;
    fflush(stdin);
    scanf("%d", &fhId);
    fileToOperate = fopen("feedHistoryData.txt", "r+");
    int found = 0;
    while (fread(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (feedHistoryInfo.id == fhId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Feeding History ID: ");
            fflush(stdin);
            scanf("%d", &feedHistoryInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &feedHistoryInfo.projectId);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f", &feedHistoryInfo.quantity);
            printf("Please Enter Food Category: ");
            fflush(stdin);
            gets(feedHistoryInfo.foodCategory);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(feedHistoryInfo.date);
            printf("Please Enter Time: ");
            fflush(stdin);
            gets(feedHistoryInfo.time);

            fseek(fileToOperate, -sizeof(feedHistoryInfo), SEEK_CUR);
            fwrite(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nFeeding History information updated\n");
    }
    else
    {
        printf("\nFeeding History with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updatefeedHistoryInfo();
    }else if (choice==2){
        feedHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete feedHistory info function
void deletefeedHistoryInfo(){
    FILE  *removeFile;

    int fHId;
    printf("Enter The Feeding History Id :");
    fflush(stdin);
    scanf("%d", &fHId);

    fileToOperate = fopen("feedHistoryData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (feedHistoryInfo.id != fHId)
        {
            fwrite(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("feedHistoryData.txt");
    rename("temp.txt", "feedHistoryData.txt");
    system("cls");
    printf("\nFeeding History Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deletefeedHistoryInfo();
    }else if (choice==2){
        feedHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// functions of feeding history management ends here

//functions of Staff management starts here
// Staff menu function
void StaffMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2 A. Add A New Staff\n");
    printf("\xDB\xDB\xDB\xDB\xB2 B. View all Staffs\n");
    printf("\xDB\xDB\xDB\xDB\xB2 C. Update An Existing Staff Info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 D. Delete an Staff Info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 E. Back to Main Menu\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    returnToStaffMenu: printf("\nChoose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewStaff();
        break;
    case 'B':
        viewAllStaff();
        break;
    case 'C':
        updateStaffInfo();
        break;
    case 'D':
        deleteStaffInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToStaffMenu;
    }
}

// add new Staff info function
void addNewStaff(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\nProvide all necessary information about the Staff\n\n");
    printf("Please Enter Staff ID: ");
    fflush(stdin);
    scanf("%d", &StaffInfo.id);
    printf("Please Enter Staff Name: ");
    fflush(stdin);
    gets(StaffInfo.name);
    printf("Please Enter Staff Email: ");
    fflush(stdin);
    gets(StaffInfo.email);
    printf("Please Enter Staff Phone-number: ");
    fflush(stdin);
    scanf("%d",&StaffInfo.phoneNumber);
    printf("Please Enter Staff Salary: ");
    fflush(stdin);
    scanf("%f", &StaffInfo.salary);

    saveStaffInfo();

    redirToSubMenu: printf("\n\t\t\t1.Do You Want To Add Another Staff info?\n\t\t\t2.Staff Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewStaff();
    }else if (choice==2){
        StaffMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save Staff info function
void saveStaffInfo()
{
    fileToOperate = fopen("StaffData.txt", "a");
    fwrite(&StaffInfo, sizeof(struct Staff), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all Staff function
void viewAllStaff(){
    system("cls");

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL STAFF LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf(" ***Expense ID*** \t***Name*** \t***Phone Number*** \t\t***Email*** \t\t***Salary***");

    fileToOperate = fopen("StaffData.txt", "r");
    while (fread(&StaffInfo, sizeof(struct Staff), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t%s\t\t0%d\t\t%s\t\t%.2f\n",StaffInfo.id,StaffInfo.name,StaffInfo.phoneNumber, StaffInfo.email,StaffInfo.salary);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t\t1. Staff Menu\n\t\t\t\t2. Main Menu\n\t\t\t\t3. Signout");
    printf("\n\n\t\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        StaffMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update Staff info function
void updateStaffInfo(){
    system("cls");
    printf("\n Update Project Information\n");

    int eId;
    printf("Please enter Staff id you want to modify: ");
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("StaffData.txt", "r+");
    int found = 0;
    while (fread(&StaffInfo, sizeof(struct Staff), 1, fileToOperate))
    {
        if (StaffInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Staff\n\n");
            printf("Please Enter Staff ID: ");
            fflush(stdin);
            scanf("%d", &StaffInfo.id);
            printf("Please Enter Staff Name: ");
            fflush(stdin);
            gets(StaffInfo.name);
            printf("Please Enter Staff Email: ");
            fflush(stdin);
            gets(StaffInfo.email);
            printf("Please Enter Staff Phone-number: ");
            fflush(stdin);
            scanf("%d",&StaffInfo.phoneNumber);
            printf("Please Enter Staff Salary: ");
            fflush(stdin);
            scanf("%f", &StaffInfo.salary);

            fseek(fileToOperate, -sizeof(StaffInfo), SEEK_CUR);
            fwrite(&StaffInfo, sizeof(struct Staff), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nStaff information updated\n");
    }
    else
    {
        printf("\nStaff with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Staff info?\n\t\t\t2. Staff Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateStaffInfo();
    }else if (choice==2){
        StaffMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete Staff info function
void deleteStaffInfo(){
    FILE  *removeFile;

    int eId;
    printf("Enter The Staff Id :");
    fflush(stdin);
    scanf("%d", &eId);

    fileToOperate = fopen("StaffData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&StaffInfo, sizeof(struct Staff), 1, fileToOperate))
    {
        if (StaffInfo.id != eId)
        {
            fwrite(&StaffInfo, sizeof(struct Staff), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("StaffData.txt");
    rename("temp.txt", "StaffData.txt");
    system("cls");
    printf("\nStaff Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Staff info?\n\t\t\t2. Staff Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteStaffInfo();
    }else if (choice==2){
        StaffMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
//functions of Staff management ends here

//functions of sells management start here
// sells menu function
void sellsMenu(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xDB\xDB\xDB\xDB\xB2 A. Add A Selling Info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 B. View All Sells\n");
    printf("\xDB\xDB\xDB\xDB\xB2 C. Update Existing Selling info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 D. Delete A Selling Info\n");
    printf("\xDB\xDB\xDB\xDB\xB2 E. Back to Main Menu\n");
    printf("\xDB\xDB\xDB\xDB\xB2\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    returnToSellsMenu: printf("\nChoose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewSells();
        break;
    case 'B':
        viewAllSells();
        break;
    case 'C':
        updateSellsInfo();
        break;
    case 'D':
        deleteSellsInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToSellsMenu;
    }
}

// add new sells info function
void addNewSells(){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAZUMDER AGRO & FISHERIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\nProvide all necessary information about the Sell\n\n");
    printf("Please Enter Selling Info ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.projectId);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &sellsInfo.amount);
    printf("Please Enter Product Name: ");
    fflush(stdin);
    gets(sellsInfo.productName);
    printf("Please Enter Quantity: ");
    fflush(stdin);
    scanf("%f",&sellsInfo.quantity);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(sellsInfo.date);

    saveSellsInfo();

    redirToSubMenu: printf("\n\t\t\t1. Do You Want To Add Another new Selling info?\n\t\t\t2. Sells Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewSells();
    }else if (choice==2){
        sellsMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save sells info function
void saveSellsInfo()
{
    fileToOperate = fopen("sellsData.txt", "a");
    fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all sells function
void viewAllSells(){
    system("cls");

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL SELLS LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf(" ***Sells ID*** ***Product*** \t***Quantity<KG>*** \t***Amount(BDT)*** \t***Date***");

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        printf("\n\n\t%d\t%s\t\t%.2f\t\t%.2f\t\t%s\n",sellsInfo.id,sellsInfo.productName,sellsInfo.quantity, sellsInfo.amount,sellsInfo.date);
    }
    fclose(fileToOperate);
    redirToViewSub: printf("\n\t\t\t\t1. Sells Menu\n\t\t\t\t2. Main Menu\n\t\t\t\t3. Signout");
    printf("\n\n\t\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        sellsMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** The Program Is Closed *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update sells info function
void updateSellsInfo(){
    system("cls");
    printf("\n Update Project Information\n");

    int sId;
    printf("Please enter project id you want to modify: ");
    fflush(stdin);
    scanf("%d", &sId);
    fileToOperate = fopen("sellsData.txt", "r+");
    int found = 0;
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id == sId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Sell\n\n");
            printf("Please Enter Selling Info ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.projectId);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &sellsInfo.amount);
            printf("Please Enter Product Name: ");
            fflush(stdin);
            gets(sellsInfo.productName);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f",&sellsInfo.quantity);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(sellsInfo.date);

            fseek(fileToOperate, -sizeof(sellsInfo), SEEK_CUR);
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nSelling Info information updated\n");
    }
    else
    {
        printf("\nSelling Info with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Selling Info info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateSellsInfo();
    }else if (choice==2){
        sellsMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete sells info function
void deleteSellsInfo(){
    FILE  *removeFile;

    int sId;
    printf("Enter The Selling Info Id :");
    fflush(stdin);
    scanf("%d", &sId);

    fileToOperate = fopen("sellsData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id != sId)
        {
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("sellsData.txt");
    rename("temp.txt", "sellsData.txt");
    system("cls");
    printf("\nSelling Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Selling info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteSellsInfo();
    }else if (choice==2){
        sellsMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
//functions of sells management ends here

// functions of report generation

void generateReport(){
    system("cls");

    int pId;
    float totalExpenses =0, totalSells =0,totalFeed=0;
    printf("\n\nPlease enter project id you want to Generate Report: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PROJECT REPORT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
           totalExpenses += expenseInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
           totalSells += sellsInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("feedHistoryData.txt", "r");
    while (fread(&feedHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (feedHistoryInfo.projectId == pId)
        {
           totalFeed += feedHistoryInfo.quantity;
        }
    }
    fclose(fileToOperate);

    printf("\n\tProject Id : %d\n", pId);
    printf("\n\tProject Total Feed Give : %.2f KG\n", totalFeed);
    printf("\n\tProject Total Sells : %.2f(BDT)\n", totalSells);
    printf("\n\tProject Total Expenses : %.2f(BDT)\n", totalExpenses);
    if(totalSells-totalExpenses >0){
        printf("\n\tNET Profit : %.2f (BDT)\n", totalSells-totalExpenses);
    }else{
        printf("\n\tNET Loss : %.2f (BDT)\n", totalExpenses-totalSells);
    }

    redirReportSub: printf("\n\t\t\t1. Do You Want To Generate Report For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Signout");
    printf("\n\n\t\t\tEnter Your Choice: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        generateReport();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** The Program Is Closed *****\n\n");
        exit(0);
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirReportSub;
    }
}

void priceEstimate(){
    system("cls");

    int pId;
    float percentage;
    char sign;
    float totalExpenses = 0,totalSells=0;
    float lossOrProfit;

    printf("\n\nPlease enter Project Id you want to estimate price: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\nPlease enter the Percentage you to make profit(X%%): ");
    fflush(stdin);
    scanf("%f%c", &percentage,&sign);

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
           totalExpenses += expenseInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
           totalSells += sellsInfo.amount;
        }
    }
    fclose(fileToOperate);

    lossOrProfit = (totalExpenses + (totalExpenses*(percentage/100))) - totalSells;

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PRICE ESTIMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n\tProject Id : %d\n", pId);
    printf("\n\tProject Total Sells Till Now : %.2f(BDT)\n", totalSells);
    printf("\n\tProject Total Expenses Till Now : %.2f(BDT)\n", totalExpenses);

    if(lossOrProfit > 0){
        printf("\n\tTo do a profit of %.2f%% you need to have more %.2f (BDT) sells from this project.\n", percentage, lossOrProfit);
    }else{
        printf("\n\tThe Project is already in profit of %.2f (BDT)\n\n",lossOrProfit*-1);
    }

    redirReportSub: printf("\n\t\t\t1. Do You Want To Estimate Price For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Signout");
    printf("\n\n\t\t\tEnter Your Choice: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        priceEstimate();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
         printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Program Is Successfully Closed \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        exit(0);
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirReportSub;
    }
}
