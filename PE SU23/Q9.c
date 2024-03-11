#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int numStudents;
    scanf("%d%*c", &numStudents);


    char names[numStudents][50];

    char name[50];
    fgets(name, sizeof(name), stdin);

    char *token = strtok(name, " ");
    int index = 0;
    while (token != NULL && index < numStudents) {
        strcpy(names[index], token);
        token = strtok(NULL, " ");
        index++;
    }

    char searchChar;
    scanf(" %c", &searchChar);

    searchChar = tolower(searchChar);

    printf("Output:\n");
    for (int i = 0; i < index; i++) {
        
        char firstChar = tolower(names[i][0]);
        if (firstChar == searchChar) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}