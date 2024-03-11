#include <stdio.h>

void Fibonacci(int n) {
    int first = 0, second = 1, next;

    printf("The Fibonacci sequence with %d numbers is:\n", n);
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d", next);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Please enter a positive integer N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N must be greater than 0!\n");
    } else {
        Fibonacci(n);
    }

    return 0;
}
