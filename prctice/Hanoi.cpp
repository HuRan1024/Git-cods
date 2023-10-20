//
// Created by reprise on 2023/10/19.
//
#include<stdio.h>

int HANOI(char a, char b, char c, int n) {   //a 为起始盘，c为终止盘。
    int ret = 0;
    if (n == 1) {
        printf("%c -> %c\n", a, c);
        ret++;
    } else {
        ret += HANOI(a, c, b, n - 1);
        printf("%c -> %c\n", a, c);
        ret++;
        ret += HANOI(b, a, c, n - 1);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", HANOI('A', 'B', 'C', n));
    return 0;
}
