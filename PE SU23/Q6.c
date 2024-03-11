#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int sum = 0, i;
    char *ch = (char*)calloc(100, sizeof(char));
    //scanf("%s", ch);
    fgets(ch, 100, stdin);
    
    for(i = 0; i < strlen(ch); i++){
        if(isdigit(ch[i]) && (ch[i] - '0') % 2 == 0)
            sum += ch[i] - '0';
    }
    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output

    printf("%d", sum);
    free(ch);
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}