//
// Created by reprise on 2023/10/21.
//
#include <stdio.h>

#define MAX 100

int main() {
    char a[MAX + 2][MAX + 2] = {0}, b[MAX][MAX] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i]);
        for (int j = n; j > 0; j--) {
            a[i][j] = a[i][j - 1];
        }
        a[i][0] = 0;
    }
    /*for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '*') {
                printf("*");
            } else {
                int sum = (a[i - 1][j - 1] == '*') +
                          (a[i - 1][j] == '*') +
                          (a[i - 1][j + 1] == '*') +
                          (a[i][j - 1] == '*') +
                          (a[i][j + 1] == '*') +
                          (a[i + 1][j - 1] == '*') +
                          (a[i + 1][j] == '*') +
                          (a[i + 1][j + 1] == '*');
                printf("%d", sum);
            }
        }
        printf("\n");
    }

    return 0;
}