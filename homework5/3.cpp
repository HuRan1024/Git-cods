//
// Created by reprise on 2023/10/27.
//
#include <stdio.h>

#define MAX 999

int main() {
    int a[MAX][MAX] = {0};
    int n;
    scanf("%d", &n);
    int number = n * n;
    int old_row = 0, old_col = n / 2 , new_row, new_col;

    a[0][old_col] = 1;
    for (int i = 2; i <= number; i++) {
        new_col = old_col + 1;        //变换坐标
        new_row = old_row - 1;
        if (new_col >= n) {
            new_col = 0;
        }
        if (new_row < 0) {
            new_row = n - 1;
        }
        if (a[new_row][new_col] == 0) {
            a[new_row][new_col] = i;
            old_col = new_col;
            old_row = new_row;
        } else {
            if ((old_row + 1) < n) {
                a[old_row + 1][old_col] = i;
                old_row++;
            } else {
                old_row = 0;
                a[0][old_col] = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

