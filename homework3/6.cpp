//
// Created by reprise on 2023/10/21.
//
#include <stdio.h>

#define MAX 1000

int main()
{
    int a[2][80] = {0};
    for (int i = 0; i < 78; i += 3) {
        a[0][i] = 'a' + i / 3;
    }
    for (int i = 1; i < 78 ; i += 3) {
        a[0][i] = 'A' + (i - 1) / 3;
    }
    for (int i = 2; i < 77; i += 3) {
        a[0][i] = ' ';
    }
    /*for (int i = 0; i < 77; i++) {
        printf("%c",a[1][i]);
    }*/
    int b[2][80];
    char c[MAX];
    int n;
    scanf("%d",&n);
    scanf("%s",c);
    for (int i = 0; i < n; i++) {         //遍历，计数
        if(c[i] >= 'a' && c[i] <= 'z') {
            a[1][3 * (c[i] - 'a')]++;
            a[1][3 * (c[i] - 'a') + 2] = 1;
        } else if (c[i] >= 'A' && c[i] <= 'Z') {
            a[1][3 * (c[i] - 'A') + 1]++;
            a[1][3 * (c[i] - 'A') + 2] = 1;
        }
    }
    int max = 0,j = 0;
    for (int i = 0; i < 77; i++) {
        if(a[1][i] > 0) {
            b[0][j] = a[0][i];
            if (b[0][j] != ' ') {
                b[1][j++] = a[1][i];
            } else {
                b[1][j++] = 0;
            }
        }
        if (max < a[1][i]) {
            max = a[1][i];
        }
    }
    if (b[0][j - 1] == ' ') {
        j--;
    }
    for (int i = max; i > 0; i--) {
        for (int k = 0; k < j; k++) {
            if (b[1][k] >= i) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < j; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < j; i++) {
        printf("%c",b[0][i]);
    }

    return 0;
}