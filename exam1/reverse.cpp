//
// Created by reprise on 2023/10/29.
//
#include <stdio.h>

#define MAX 100005

char a[MAX];

int main() {
    int len;
    scanf("%d %s", &len, a);

    for (int i = len - 1; i >= 0; i--) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] + 'a' - 'A';
        } else if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] = a[i] + 'A' - 'a';
        }
        printf("%c", a[i]);
    }

    return 0;
}