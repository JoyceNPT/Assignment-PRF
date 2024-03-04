#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == m) {
                m += 2;
                found = 1;
                break;
            }
        }

        if (!found || m > 2001000) {
            break;
        }
    }

    printf("%d\n", m);

    return 0;
}