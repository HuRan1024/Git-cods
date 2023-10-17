//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>

int main() {
    int n;
    int a[2001] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * i <= n; j++) {
            if (a[i * j] == 0) {
                a[i * j] = 1;
            } else {
                a[i * j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}