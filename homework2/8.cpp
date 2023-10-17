//
// Created by reprise on 2023/10/15.
//
#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);
    char a[MAX];
    char b[MAX];
    char b1 = '0', b2 = '0';
    int j = 0;

    scanf("%s", a);
    for (int i = 0; i < n / 2; i++) {
        if (a[i] == '?') {
            if (a[n - i - 1] != '?') {
                printf("%c", a[n - i - 1]);
                b[j++] = a[n - i - 1];
            } else {
                printf("%c%c", b1, b2);
                b[j++] = b1;
                b[j++] = b2;
                if (b2 == '9') {
                    b1++;
                    b2 = '0';
                } else {
                    b2++;
                }
            }
        } else {
            printf("%c", a[i]);
            b[j++] = a[i];
        }
    }
    if (n % 2 == 1) {
        b[j] = a[n / 2];
    } else {
        j--;
    }
    for (; j >= 0; j--) {
        printf("%c", b[j]);
    }
    return 0;
}