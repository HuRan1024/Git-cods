//
// Created by reprise on 2023/10/15.
//
#include<stdio.h>
#include<math.h>

int mypow(int x, int y) {
    int f = 1, i;
    if (y == 0) {
        f = 1;
    } else {
        for (i = 1; i <= y; i++) {
            f *= x;
        }
    }
    return f;
}

int main() {
    int i, r, x, y, s, count, count1;
    printf("0 ");
    for (i = 1; i <= 200000; i++) {
        i = 25;
        r = i, s = 0, x = 10, y = 1, count = 1, count1 = 0;
        for (count1 = 0; r > 0; count1++) {       //求位数
            r = r / 10;
        }
        for (count = 1; count <= count1; count++) {
            s += ((i % x) / y) * i % (mypow(10, count1 - count + 1)) * (mypow(10, count - 1));
            x *= 10, y *= 10;
        }
        if (i == s) {
            printf("%d ", i);
        }
    }
    return 0;
}