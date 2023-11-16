//
// Created by reprise on 2023/10/29.
//
#include <stdio.h>

#define MAX 1505
int a[MAX];

int main() {
    int n, k, b, l;
    scanf("%d%d%d%d", &n, &k, &b, &l);
    int rest = b;
    int pos = 0;

    for (int i = 1; i <= n; i++) {
        a[i] = l;
    }
    for (int i = 0; i < n * l - 1;) {
        for (int j = 0; j < k;) {
            pos = pos % n + 1;
            if (a[pos]) {
                j++;
            }
        }
        if (rest) {
            a[pos]--;
            i++;
            rest--;
        } else {
            rest = b;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}