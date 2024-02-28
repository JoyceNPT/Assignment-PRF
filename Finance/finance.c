#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char date[MAX_DATE_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;
int year;

int chooseCategory(); // Function declaration
void enter_expense(); // Function declaration
void displayExpenses(Expense expenses[], int numExpenses);
void get_monthly_expense_statistics();
void save_expenses_to_file(const char* filename);

int print_startmenu();

void enterExpenses(float expenses[]);

int main() {
    int keep_running = 1;

    while (keep_running) {
        keep_running = print_startmenu();
    }

    return 0;
}

int print_startmenu() {
    int choice = 0;

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
        return 1;
    }

    switch (choice) {
        case 1:
            enter_expense();
            break;
        case 2:
            displayExpenses(expenses, numExpenses);
            break;
        case 3:
            get_monthly_expense_statistics();
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

    return 1;
}

void enter_expense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("List of current expenses is full.\n");
        return;
    }

    Expense newExpense;

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

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("Date\t\tCategory\tAmount\n");
    printf("-------------------------------------------------------- --\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    printf("-------------------------------------------------------- --\n");

    // Wait for user input before returning to the menu
    printf("\nPress any key and Enter to return to the main menu: ");
    char dummy;
    scanf(" %c", &dummy); // Read and discard a character
}


void enterExpenses(float expenses[]) {
    printf("Enter the year (YYYY): ");
    scanf("%d", &year);

    if (year <= 0 || year > 9999) {
        printf("Invalid year. Please enter a year from 1 - 9999.\n");
        return;
    }

    for (int i = 0; i < 12; i++) {
        printf("Enter expenses for month %d: ", i + 1);
        scanf("%f", &expenses[i]);
    }
}


void get_monthly_expense_statistics() {
    float monthlyExpenses[12];
    enterExpenses(monthlyExpenses);

    float total = 0, average = 0, min = monthlyExpenses[0], max = monthlyExpenses[0];

    for (int i = 0; i < 12; i++) {
        total += monthlyExpenses[i];
        if (monthlyExpenses[i] < min) min = monthlyExpenses[i];
        if (monthlyExpenses[i] > max) max = monthlyExpenses[i];
    }
    average = total / 12;

    printf("||------------------------||\n");
    printf("|| -YEAR %d- \n", year);
    printf("||-------------------------||---------------||\n");
    printf("|| Total Expenses || %.2f \n", total);
    printf("||-------------------------||---------------||\n");
    printf("|| Average Monthly Expense || %.2f \n", average);
    printf("||-------------------------||---------------||\n");
    printf("|| Minimum Expense || %.2f \n", min);
    printf("||-------------------------||---------------||\n");
    printf("|| Maximum Expense || %.2f \n", max);
    printf("||-------------------------||---------------||\n");

    // Wait for user input before returning to the menu
    printf("\nPress any key and Enter to return to the main menu: ");
    char dummy;
    scanf(" %c", &dummy); // Read and discard a character
}
