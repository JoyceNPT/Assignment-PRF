#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void bubble_Sort(int a[], int size){
    int i, j;
    for (i = size - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if (a[j] < a[j+1]){
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }
}

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n, i;
    scanf("%d", &n);
    int *a = (int*)calloc(n, sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",  &a[i]);

    bubble_Sort(a, n);
    
    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output

    for(i = 0; i < n; i++){
        if(a[i] % 2 == 1)
            printf("%d\n", a[i]);
    }

    for(i = 0; i < n; i++){
        if(a[i] % 2 == 0)
            printf("%d\n", a[i]);
    }

    free(a);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}