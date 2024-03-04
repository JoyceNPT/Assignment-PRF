#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2001000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bool found = false;
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++) {
        hash[a[i]] = true;
    }

    while (1) {
        found = false;
        if (hash[m] == true) {
            m += 2;
            found = true;
        }

        if (m > 2001000 || !found) {
            break;
        }
    }

    printf("%d\n", m);

    return 0;
}
