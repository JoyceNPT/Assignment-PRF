#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
    int n, i, j;
    int *a = (int*)calloc(50, sizeof(int));
    int seen[100] = {0};
    scanf("%d%*c", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = n - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if (a[j] > a[j+1]){
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }

  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(i = 0; i < n; i++){
        if(!seen[a[i]]){
            printf("%d\n", a[i]);
            seen[a[i]] = 1;
        }
    }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}