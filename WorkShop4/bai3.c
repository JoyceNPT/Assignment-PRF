#include <stdio.h>
#include <ctype.h>
#include <string.h>

int palindrome(char *str);

int main() {
    char sent[206];
    fgets(sent, sizeof(sent), stdin);

    if (palindrome(sent)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

int palindrome(char *str) {
    int len = strlen(str);
    char fixed[len + 1];

    int j = 0;
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (isupper(c)) {
            c = tolower(c);
        }
        if (isalnum(c)) {
            fixed[j++] = c;
        }
    }
    fixed[j] = '\0';

    int left = 0;
    int right = j - 1;
    while (left < right) {
        if (fixed[left] != fixed[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
