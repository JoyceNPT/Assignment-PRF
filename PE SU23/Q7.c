#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n, r, c;
    scanf("%d", &n);
    int a[n][n];
    for(r = 0; r < n; r++)
        for(c = 0; c < n; c++)
            scanf("%d", &a[r][c]);

    int max = a[0][0];
    for(r = 0; r < n; r++){
        for(c = 0; c < n; c++){
            if(r == c){
                if(max < a[r][c])
                    max = a[r][c];
            }
        }
    }

    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output
    printf("%d",  max);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}