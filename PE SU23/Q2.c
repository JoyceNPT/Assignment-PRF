#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    int i, n;
    double sum = 0;
    scanf("%d", &n);
    double *a = (double*)calloc(n, sizeof(double));
    for(i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output

    for(i = 0; i < n; i++)
        sum += a[i];
    printf("%.3lf", (double) sum / n);
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}