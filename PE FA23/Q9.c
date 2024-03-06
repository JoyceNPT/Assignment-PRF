#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
    int i, n, count = 0;;
    scanf("%d%*c", &n);
    char a[50][50];
    char find[50];
    for(i = 0; i < n; i++)
        scanf("%s", &a[i]);

    scanf("%s", find);

    for(i = 0; i < n; i++){
        if(strstr(a[i], find) != NULL){
            count++;
        }
    }

  
  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

    printf("%d", count);


  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}