#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_CURRENCY_LENGTH 5
#define MAX_DATE_LENGTH 11

// Structure to hold an expense record
typedef struct {
    char date[MAX_DATE_LENGTH]; // Assuming date format YYYY-MM-DD
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

int chooseCategory(); // Function declaration
void enter_expense(); // Function declaration

// Function to display expense records
void displayExpenses(Expense expenses[], int numExpenses) {
    printf("Date\t\tCategory\tAmount\n");
    printf("-------------------------------------------------------- --\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    printf("-------------------------------------------------------- --\n");
}

// Function to filter expenses by date range
void filterByDate(Expense expenses[], int numExpenses, char startDate[], char endDate[]) {
    printf("Expenses between %s and %s:\n", startDate, endDate);
    printf("-------------------------------------------------------- --\n");
    printf("Date\t\tCategory\tAmount\n");
    printf("-------------------------------------------------------- --\n");
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, startDate) >= 0 && strcmp(expenses[i].date, endDate) <= 0) {
            printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
        }
    }
    printf("-------------------------------------------------------- --\n");
}

int print_startmenu();

int main() {
    int keep_running = 1;

    while (keep_running) {
        keep_running = print_startmenu();
    }

    return 0;
}

int print_startmenu() {
    int choice = 0; // Initialize choice

    printf("\n ===========================================\n ");
    printf("| Personal Finance Management |\n");
    printf(" | 1. Enter Expenses |\n");
    printf(" | 2. List Expenses |\n");
    printf(" | 3. Get Monthly Expense Statistics |\n");
    printf(" | 4. Save Expenses to File |\n");
    printf(" | 5. Exit |\n");
    printf(" ===========================================\n");
    printf("\nEnter your choice: ");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid choice. Please try again.\n");
        return 1; // Indicate error
    }

    switch (choice) {
        case 1:
            enter_expense();
            break;
        case 2:
            displayExpenses(expenses, numExpenses);
            break;
        case 3:
            // Implement getting monthly expense statistics
            break;
        case 4:
            // Implement saving expenses to file
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            fprintf(stderr, "Unexpected error: invalid choice.\n");
            exit(1);
    }

    return 1; // Indicate successful operation (non-exit choice)
}

void enter_expense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("List of current expenses is full.\n");
        return;
    }

    Expense newExpense; // Remove 'struct'

    int categoryChoice = chooseCategory();
    switch (categoryChoice) {
        case 1:
            strcpy(newExpense.category, "Products");
            break;
        case 2:
            strcpy(newExpense.category, "Conversion valve");
            break;
        case 3:
            strcpy(newExpense.category, "Other");
            break;
        default:
            strcpy(newExpense.category, "Other");
            break;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    printf("Enter the amount spent: ");
    scanf("%f", &newExpense.amount);

    expenses[numExpenses++] = newExpense;

    printf("Expense added successfully.\n");
}

int chooseCategory() {
    int choice;
    printf("Select expense category:\n");
    printf("1. Products\n");
    printf("2. Conversion valve\n");
    printf("3. Other\n");
    printf("Selection: ");
    scanf("%d", &choice);
    return choice;
}
