//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[500] = {0};
    int j = 0;
    for (int i = 0, cnt = 0; cnt < n - 1; cnt++) {
        j = 0;
        while (j != k) {
            if (a[i] == 0) {
                j++;
            }
            if (i < n - 1) {
                i++;
            } else {
                i = 0;
            }
        }
        if (i != 0) {
            a[i - 1] = 1;
        } else {
            a[n - 1] = 1;
        }
       // printf("%d\n", i);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}