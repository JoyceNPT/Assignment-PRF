#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
    char *ch = (char*)calloc(100, sizeof(char));
    char c;
    int i, flag = 0;

    scanf("%[^\n]%*c", ch);
    scanf("%c", &c );

    
  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(i = 0; i < strlen(ch); i++){
        if(ch[i] == c){
            ch[i] = toupper(ch[i]);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("Character '%c' not found", c);
    else
        printf("%s", ch);



  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}