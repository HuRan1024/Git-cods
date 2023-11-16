//
// Created by reprise on 2023/10/27.
//
#include <stdio.h>

int Change(int x, int b);  // 将b进制转换为10进制

int main() {
 //   printf("%d", Change(42, 13));
    int p, q, r, b;
    scanf("%d%d%d", &p, &q, &r);
    for (b = 2; b <= 40; b++) {
        if (Change(p, b) * Change(q, b) == Change(r,b) && Change(r,b)) {
            printf("%d", b);
            break;
        }
    }
    if (b == 41) {
        printf("0");
    }

    return 0;
}

int Change(int x, int b) {
    int a[5];
    int i = 0;
    do {
        a[i] = x % 10;
        x /= 10;
        i++;
    } while (x > 0);
    for (i--; i >= 0; i--) {
        x = x * b + a[i];
        if (a[i] >= b) {
            return 0;
        }
    }
    return x;
}

