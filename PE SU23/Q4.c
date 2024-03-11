#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int isPrime(int n);

int nextPrime(int n){
    //Tim so nguyen to tiep theo của một so
    //Example: 2 ===> 3
    //         3 ===> 5
    while (1)
    {
        n++;
        if(isPrime(n) == 1)
        return n;
    }

}

int isPrime(int n){
    //Kiem tra xem n có phải là so nguyen to hay khong
    //Duyet tu 2 den n/2 hoac can bac hai cua n
    int i;
    for(i = 2; i <= n / 2; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n, i, j;
    int prevPrime = 2;
    scanf("%d", &n);
    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    // ouput: logic ( vòng lặp, if else,.... ) + printf để in ra output
    for(i = 1; i <= n; i++){
        for(j = 1;j <= n; j++){
            if(j <= i){
                printf("%d ", prevPrime);
                prevPrime = nextPrime(prevPrime);
            }
            else
                printf(" ");
        }
        printf("\n");
    }

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}