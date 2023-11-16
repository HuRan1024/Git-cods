//
// Created by reprise on 2023/10/21.
//
#include<stdio.h>

#define MAX 50

int main() {
    int n, m, x0, y0;
    scanf("%d%d%d%d", &n, &m, &x0, &y0);
    char a[MAX + 2][MAX + 2];
    char b[MAX * MAX][2];
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i]);
        for (int j = m; j > 0; j--) {
            a[i][j] = a[i][j - 1];
        }
        a[i][0] = 0;
    }
    int x = x0, y = y0, k = 0;

    b[k][0] = x0;
    b[k++][1] = y0;
    while ((a[x][y - 1] == '#') || (a[x][y + 1] == '#') || (a[x - 1][y] == '#') || (a[x + 1][y] == '#')) {
        if (a[x][y - 1] == '#') {
            a[x][y] = '_';
            y = y - 1;
            b[k][0] = x;
            b[k++][1] = y;
        } else if (a[x][y + 1] == '#') {
            a[x][y] = '_';
            y = y + 1;
            b[k][0] = x;
            b[k++][1] = y;
        } else if (a[x - 1][y] == '#') {
            a[x][y] = '_';
            x = x - 1;
            b[k][0] = x;
            b[k++][1] = y;
        } else if (a[x + 1][y] == '#') {
            a[x][y] = '_';
            x = x + 1;
            b[k][0] = x;
            b[k++][1] = y;
        }
    }
    printf("%d\n",k);
    for (int i = 0; i < k; i++) {
        printf("%d %d\n",b[i][0],b[i][1]);
    }

    return 0;
}