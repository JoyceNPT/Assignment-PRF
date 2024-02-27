#include <stdio.h>
#include <stdlib.h>

int print_startmenu();
void enter_expenses();
void list_expenses();
void get_monthly_expense_statistics();

int main() {
    int keep_running = 1;

    while (keep_running) {
        keep_running = print_startmenu();
    }
    
    return 0;
}



int print_startmenu() {
    int choice;

    printf("\n  ===========================================\n");
    printf(" |      Personal Finance Management          |\n");
    
    printf(" |      1. Enter Expenses                    |\n");
    printf(" |      2. List Expenses                     |\n");
    printf(" |      3. Get Monthly Expense Statistics    |\n");
    printf(" |      4. Exit                              |\n");
    printf("  ===========================================\n");
    printf("\nEnter your choice: ");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid choice. Please try again.\n");
        return 1; // Indicate error
    }
    switch (choice) {
        case 1:
            enter_expenses();
            break;
        case 2:
            list_expenses();
            break;
        case 3:
            get_monthly_expense_statistics();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            fprintf(stderr, "Unexpected error: invalid choice.\n");
            exit(1);
    }

    return 1; // Indicate successful operation (non-exit choice)
}


void enter_expenses() {
    printf("Enter Expenses called.\n");
}

void list_expenses() {
    printf("List Expenses called.\n");
}

void get_monthly_expense_statistics() {
    printf("Get Monthly Expense Statistics called.\n");
}

