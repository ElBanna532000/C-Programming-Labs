#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#define UP 65
#define DOWN 66
#define ESC 27
#define ENTER 10
#define HOME 72
#define SIZE 50

typedef struct Employee {
    int id;
    char name[30];
    int salary;
} Employee;

//Employee employees[SIZE];

void show_menu(int cursor) {
    system("clear"); // Clear the terminal
    textcolor(BLACK); // Set default color to black.
    // Highlight the selected menu option based on the cursor position.
    for (int i = 0; i < 5; i++) {
        if (i == cursor) {
            textcolor(RED); // Highlight selected option in red.
        }

        switch(i) {
            case 0:
                printf("NEW\n");
                break;
            case 1:
                printf("DISPLAY\n");
                break;
            case 2:
                printf("MODIFY\n");
                break;
            case 3:
                printf("DELETE\n");
                break;
            case 4:
                printf("EXIT\n");
                break;
        }
        textcolor(BLACK);   // Reset color to Black after printing each option.
    }
}

int addEmployee(Employee employees[], int count){
    int flag=1;
    int target_id;
    int again;
    if(count >= SIZE){
        printf("Size is full, cannot add a new employee\n");
        return count;
    }
    while(flag){
        char ch;
        while(1){
            int i;
            int isFound=0;

            printf("Enter employee id: ");
            if(!(scanf("%d%c", &employees[count].id, &ch)==2 && ch=='\n')){
                printf("Invalid input. Please enter a valid numeric ID.\n");
                while(getchar()!='\n');
                continue;
            }
            else if(employees[count].id <= 0){
                printf("ID cannot be 0 or a negative number.\n");
                continue;
            }
            else{
                for(i=0; i<count; i++){
                    if(employees[count].id == employees[i].id){
                        printf("ID already exists, try a different one\n");
                        isFound=1;
                        break;
                    }
                }
            }

            if(!isFound){   //if(0)
                break;
            }
        }

        printf("Enter employee name: ");
        scanf("%s", employees[count].name);
        while(1){
            printf("Enter employee salary: ");
            if(!(scanf("%d%c", &employees[count].salary, &ch)==2 && ch=='\n')){
                printf("Invalid input. Please enter a valid numeric Salary.\n");
                while(getchar()!='\n');
                continue;
            }else if(employees[count].salary <= 0){
                printf("Salary cannot be 0 or a negative number\n");
                continue;
            }
            break;
        }
        printf("Employee added successfully!\n\n");
        count++;
        printf("================================================\n");

        printf("If you want to add a new employee press 1, if not press 0: ");
        while (1) {
            if (!(scanf("%d%c", &again, &ch) == 2 && ch == '\n')) {
                printf("Invalid input. Please enter 1 to add another employee or 0 to exit: ");
                while (getchar() != '\n');  // Clear input buffer
                continue;
            }
            if(again == 1) {
                flag = 1;
                break;  // Continue to add another employee
            }else if(again == 0) {
                flag = 0;
                break;
            }else {
                printf("Invalid input. Please enter 1 to add another employee or 0 to exit: ");
            }
        }
    }
    printf("Goodbye, Press any ENTER to return to the main menu...\n");
    getch();
    return count;
}

void displayEmployees(Employee employees[], int count){
    for(int i=0; i<count; i++){
        printf("ID: %d, Name: %s, Salary: %d\n",employees[i].id, employees[i].name, employees[i].salary);
        printf("================================================\n");
    }
}

void modifyEmployee(Employee employees[], int count){
    if (count == 0) {
        printf("No employees to modify. Please add employees first.\n");
        printf("Press any key to return to the menu...");
        getch();
        return;
    }
    int target_id;
    int found=0;
    int choice;
    char ch;
    printf("Modifying Employees\n");
    printf("================================================\n");
    printf("Enter employee ID that you want to modify on: ");
    scanf("%d", &target_id);

    for(int i=0; i<count; i++){
        if(target_id==employees[i].id){
            found=1;
            printf("\nEmployee found! Current details:\n");
            printf("ID: %d, Name: %s, Salary: %d\n", employees[i].id, employees[i].name, employees[i].salary);
            printf("Type 1 to change ID \nType 2 to change Name \nType 3 to change Salary\n");
            printf("Your choice: ");
            scanf("%d", &choice);

            switch (choice){
                case 1:
                    printf("Changing ID\n");
                    while(1){
                        printf("Enter new ID for employee %s (current ID: %d): ", employees[i].name, employees[i].id);
                        if(!(scanf("%d%c", &employees[i].id, &ch)==2 && ch=='\n')){
                            printf("Invalid input. Please enter a valid numeric ID.\n");
                            while(getchar()!='\n');
                            continue;
                        }
                        else if(employees[i].id <= 0){
                            printf("ID cannot be 0 or a negative number.\n");
                            continue;
                        }
                        break;
                    }

                    printf("ID has been changed successfully!\n");
                    break;
                case 2:
                    printf("Changing Name\n");
                    printf("Enter new Name foModifyingr employee %s (current ID: %d): ", employees[i].name, employees[i].id);
                    scanf("%s", employees[i].name);
                    printf("Name has been changed successfully!\n");
                    while(getchar()!='\n');
                    break;
                case 3:
                    printf("Changing Salary\n");
                    while(1){
                        printf("Enter new Salary for employee %s (current ID: %d): ", employees[i].name, employees[i].id);

                        if(!(scanf("%d%c", &employees[i].salary, &ch)==2 && ch=='\n')){
                            printf("Invalid input. Please enter a valid numeric Salary.\n");
                            while(getchar()!='\n');
                            continue;
                        }else if(employees[i].salary <= 0){
                            printf("Salary cannot be 0 or a negative number\n");
                            continue;
                        }
                        printf("Salary has been changed successfully!\n");
                        break;
                    }
                    break;
                default:
                    printf("Not a valid input");
                    break;
            }
        }
    }
    if(!found){
        printf("ID %d is not found\n", target_id);
        getch();
    }

    printf("Press any key to return to the menu...");
    getch();

}


int main() {
    Employee employees[SIZE];
    int count =0;
    int cursor = 0;  // Initialize cursor position
    char realkey=0;
    int isRunning = 1;  // Flag to keep the menu running

    show_menu(cursor);  // Display the initial menu
    while (isRunning) {
        char firstkey = 0;
        firstkey = getch();  // Get user input

        if(firstkey==ENTER){    //first Key condition for the ENTER btn
            system("clear");

            if(cursor==0){
                count = addEmployee(employees,count);
                show_menu(cursor);
            }

            else if(cursor==1){
                printf("Displaying all Employees\n");
                printf("================================================\n");
                displayEmployees(employees, count);
                printf("\nPress any key to return to the menu...");
                getch();
                system("clear");
                show_menu(cursor);
            }
            else if(cursor==2){

                displayEmployees(employees, count);
                modifyEmployee(employees, count);
                system("clear");
                show_menu(cursor);
            }
            else{
                isRunning=0;
            }
        }

        if (firstkey == 27) {
            getch();
            realkey=getch();

            if (realkey == UP) {  // Move cursor up
                cursor = (cursor == 0) ? 4 : cursor - 1;  // Wrap to last option if at top ---
                show_menu(cursor);
            } else if (realkey == DOWN) {  // Move cursor down
                cursor = (cursor == 4) ? 0 : cursor + 1;  // Wrap to first option if at bottom
                show_menu(cursor);
            }
            else if(realkey==HOME){
                cursor=0;
                show_menu(cursor);
            }
        }
    }
    textcolor(BLACK);   // Reset color to default
    return 0;
    }

