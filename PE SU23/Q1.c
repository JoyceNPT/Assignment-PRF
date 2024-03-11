#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int i, max;
    int *a = (int*)calloc(3, sizeof(int));
    for(i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    
    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output

    for(i = 0, max = a[0]; i < 3; i++){
        if(a[i + 1] >= max)
            max = a[i + 1];
    }

    printf("%d", max);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}