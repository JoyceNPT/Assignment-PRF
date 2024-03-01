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
    char currency[4];
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void enterExpense();
void listExpenses();
void listExpensesByMonth();
void listExpensesByCustomPeriod();
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
        system("clear || cls");
    } while (choice != 5);

    return 0;
}

//Function 1:  Enter expense
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

    strcpy(newExpense.currency, "VND");

    expenses[numExpenses++] = newExpense;

    printf("Expense added successfully.\n");
}


//Function 2: List Expenses
void listExpenses() {
    int choice;
    system("cls");
    printf("\n||----------------------------------------------------||\n");
    printf("|| List Expenses                                      ||\n");
    printf("||----------------------------------------------------||\n");
    printf("|| 1. List all expenses                               ||\n");
    printf("|| 2. List expenses for a specific month              ||\n");
    printf("|| 3. List expenses for a custom period               ||\n");
    printf("||----------------------------------------------------||\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nList of All Expenses:\n");
            break;
        case 2:
            listExpensesByMonth();
            return;
        case 3:
            listExpensesByCustomPeriod();
            return;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            return;
    }

    printf("Date\t\tCategory\tAmount\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t%-10.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].currency);
    }
    printf("------------------------------------------\n");
}


void listExpensesByMonth() {
    char month[3];
    printf("Enter the month (MM): ");
    scanf("%s", month);

    printf("\nList of Expenses for Month %s:\n", month);
    printf("Date\t\tCategory\tAmount\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        char expenseMonth[3];
        strncpy(expenseMonth, expenses[i].date + 5, 2); // Extract month part from date string
        expenseMonth[2] = '\0'; // Null-terminate the string
        if (strcmp(expenseMonth, month) == 0) {
            printf("%s\t%s\t\t%-10.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].currency);
        }
    }
    printf("------------------------------------------\n");
}


void listExpensesByCustomPeriod() {
    char startDate[MAX_DATE_LENGTH];
    char endDate[MAX_DATE_LENGTH];
    printf("Enter the start date (YYYY-MM-DD): ");
    scanf("%s", startDate);
    printf("Enter the end date (YYYY-MM-DD): ");
    scanf("%s", endDate);

    printf("\nList of Expenses for Period %s to %s:\n", startDate, endDate);
    printf("Date\t\tCategory\tAmount\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, startDate) >= 0 && strcmp(expenses[i].date, endDate) <= 0) {
            printf("%s\t%s\t\t%-10.2f %s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].currency);
        }
    }
    printf("------------------------------------------\n");
}


//Function 3: Monthly Expense Statistics
void getMonthlyExpenseStatistics() {
    int year;
    printf("Enter the year (YYYY): ");
    scanf("%d", &year);

    float monthlyTotal[12] = {0}; // Array to store total expenses for each month
    float totalExpenses = 0; // Total expenses for the entire year

    for (int i = 0; i < numExpenses; i++) {
        int expenseYear, expenseMonth;
        sscanf(expenses[i].date, "%d-%d", &expenseYear, &expenseMonth); // Extract year and month from date
        if (expenseYear == year) {
            monthlyTotal[expenseMonth - 1] += expenses[i].amount; // Accumulate expenses for each month
            totalExpenses += expenses[i].amount; // Accumulate total expenses for the year
        }
    }

    printf("\nMonthly Expense Statistics for Year %d:\n", year);
    printf("Month\tTotal Expenses\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < 12; i++) {
        printf("%d\t%.2f\n", i + 1, monthlyTotal[i]);
    }
    printf("------------------------------------------\n");
    printf("Total Expenses for Year %d: %.2f\n", year, totalExpenses);
}


//Function 4: Save Expenses to File
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
