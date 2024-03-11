#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
    char binary[9];
    int len, i, carry = 1;

    scanf("%s", binary);
    
    len = strlen(binary);
    for(i = 0; i < len; i++){
        binary[i] = (binary[i] == '1') ? '0' : '1';
    }

    for(i = len - 1; i >= 0; i--){
        if(binary[i] == '0' &&  carry == 1){
            binary[i] = '1';
            carry = 0;
        }
        else if(binary[i] ==  '1' && carry == 1) {
            binary[i] = '0';
            carry = 1;
        }
    }



  
  // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:


    printf("%s", binary);




  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return(0);
}