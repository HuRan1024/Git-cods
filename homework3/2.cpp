//
// Created by reprise on 2023/10/21.
//
#include <stdio.h>

#define MAX 3000

int JUDGE(char a, char b, char c) {
    if (a && b && c) {
        return 0;
    } else if (a && b && !c) {
        return 1;
    } else if (a && !b && c) {
        return 1;
    } else if (a && !b && !c) {
        return 0;
    } else if (!a && b && c) {
        return 1;
    } else if (!a && b && !c) {
        return 1;
    } else if (!a && !b && c) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    //printf ("%d", JUDGE(1,0,0));
    int m, n;
    char a[MAX][MAX + 2] = {0}; //扩充矩阵
    scanf("%d%d", &m, &n);
    scanf("%s", a[0]);
    for (int i = n; i > 0 ; i--) {
        a[0][i] = a[0][i - 1] - '0';
    }
    a[0][0] = 0;
    /*for (int i = 1; i <= MAX; i++) {
        printf("%d", a[0][i]);
    }
    //printf("%s",a[0]);
    printf("\n");*/
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = JUDGE(a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1]);
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
