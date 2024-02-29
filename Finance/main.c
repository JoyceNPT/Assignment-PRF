#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char date[MAX_DATE_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    char currency[4]; // Maximum currency string length including null terminator
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void enterExpense();
void listExpenses();
void getMonthlyExpenseStatistics();
void saveExpensesToFile(const char* filename);

void loadExpensesFromFile(const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(fp, "%s %s %f %s", expenses[numExpenses].date, expenses[numExpenses].category, &expenses[numExpenses].amount, expenses[numExpenses].currency) == 4) {
        numExpenses++;
    }

    fclose(fp);
    printf("Expenses loaded from %s.\n", filename);
}

int main() {
    // Load expenses from file
    loadExpensesFromFile("expenses.txt");

    int choice;

    do {
        printf("\n||------------------------------------------------||\n");
        printf("||            Personal Finance Management         ||\n");
        printf("||------------------------------------------------||\n");
        printf("||      1. Enter Expenses                         ||\n");
        printf("||      2. List Expenses                          ||\n");
        printf("||      3. Get Monthly Expense Statistics         ||\n");
        printf("||      4. Save Expenses to File                  ||\n");
        printf("||      5. Exit                                   ||\n");
        printf("||------------------------------------------------||\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterExpense();
                break;
            case 2:
                listExpenses();
                break;
            case 3:
                getMonthlyExpenseStatistics();
                break;
            case 4:
                saveExpensesToFile("expenses.txt");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Wait for user to press Enter before clearing the screen and returning to menu
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for Enter
        system("clear || cls"); // Clear screen

    } while (choice != 5);

    return 0;
}

void enterExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("List of current expenses is full.\n");
        return;
    }

    Expense newExpense;

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    printf("Enter the category: ");
    scanf("%s", newExpense.category);

    printf("Enter the amount spent: ");
    scanf("%f", &newExpense.amount);

    strcpy(newExpense.currency, "VND"); // Set currency to VND

    expenses[numExpenses++] = newExpense;

    printf("Expense added successfully.\n");
}

void listExpenses() {
    printf("\nList of Expenses:\n");
    printf("Date\t\tCategory\tAmount\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t%-10.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].currency);
    }
    printf("-----------------------------------------\n");
}

void getMonthlyExpenseStatistics() {
    // Implementation of this function is left as an exercise for you
}

void saveExpensesToFile(const char* filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%s %s %.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].currency);
    }

    fclose(fp);
    printf("Expenses saved to %s.\n", filename);
}
