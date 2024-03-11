#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int a, b, max, carry = 1;
    scanf("%d %d", &a, &b);
    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output
    max = (a > b) ? a : b;
    while (1)
    {
        if(max * carry % a == 0 && max * carry % b == 0){
            printf("%d", max * carry);
            break;
        }
        carry++;
    }
    
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}