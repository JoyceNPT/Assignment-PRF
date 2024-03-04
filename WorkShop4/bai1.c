#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool phone_number_validation(const char *phone_number) {
    int len = strlen(phone_number);
    int i;

    if (len >= 100) {
        return false;
    }

    if (len == 14 && phone_number[0] == '(' && phone_number[4] == ')' && phone_number[5] == ' ' && phone_number[9] == '-') {
        for (i = 1; i < 4; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        for (i = 6; i < 9; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        for (i = 10; i < 14; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        return true;
    }

    if (len == 12 && phone_number[3] == '-' && phone_number[7] == '-') {
        for (i = 0; i < 3; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        for (i = 4; i < 7; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        for (i = 8; i < 12; i++) {
            if (!isdigit(phone_number[i])) {
                return false;
            }
        }
        return true;
    }

    return false;
}

int main() {
    char phone_number[100];
    fgets(phone_number, sizeof(phone_number), stdin);
    phone_number[strcspn(phone_number, "\n")] = '\0';

    if (phone_number_validation(phone_number)) {
        printf("valid\n");
    } else {
        printf("not valid\n");
    }

    return 0;
}
