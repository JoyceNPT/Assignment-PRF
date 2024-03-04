#include <stdio.h>

int count_words(char *str);

int main() {
    char str[100];
    fgets(str, 100, stdin);

    int words = count_words(str);
    printf("%d\n", words);

    return 0;
}

int count_words(char *str) {
    int words = 0;
    int inWord = 0;

    
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && inWord) {
            words++;
            inWord = 0;
        }
        else if (str[i] != ' ' && str[i] != '\t') {
            inWord = 1;
        }
    }

    if (inWord) {
        words++;
    }

    return words;
}
