#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, r, c;
    double average = 0;
    scanf("%d", &n);
    int a[n][n];

    for(r = 0; r < n; r++)
        for(c = 0; c < n; c++)
            scanf("%d", &a[r][c]);

  
  
  
  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(r = 0; r < n; r++){
        for(c = 0; c < n; c++){
            if(r == c)
                average += a[r][c];
        }
    }
    average /= n;
    printf("%.2lf", average);





  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}