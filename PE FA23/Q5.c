#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
    int i, j, n;
    scanf("%d", &n);
    int *a = (int*)calloc(n, sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = n - 1; i > 0; i--){
        for(j = 0;  j < i; j++)
            if(a[j] < a[j + 1]){
                a[j] = a[j] + a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] = a[j] - a[j + 1];
            }
    }
  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(i = 0; i < n; i++){
        if(a[i] % 2 == 1)
          printf("%d\n", a[i]);
    }

    for(i = 0; i < n; i++){
        if(a[i] % 2 == 0)
          printf("%d\n", a[i]);
    }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}