//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
#include <math.h>

char a[1050][2500];

void paint(int n, int x, int y) {
    if (n == 1) {
        a[x][y] = a[x - 1][y + 1] = '/';
        a[x][y + 1] = a[x][y + 2] = '_';
        a[x - 1][y + 2] = a[x][y + 3] = '\\';
        return;
    }
    paint(n - 1, x, y);
    paint(n - 1, x, y + pow(2, n));
    paint(n - 1, x - pow(2, n - 1), y + pow(2, n - 1));
}

int main() {
    int n;
    scanf("%d", &n);
    int xm = pow(2, n);
    int ym = pow(2, n + 1);
    for (int i = 0; i < xm; i++) {
        for (int j = 0; j < ym; j++) {
            a[i][j] = ' ';
        }
    }
    paint(n, xm - 1, 0);
    for (int i = 0; i < xm; i++) {
        for (int j = 0; j < ym; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}