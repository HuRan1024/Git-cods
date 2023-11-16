//
// Created by reprise on 2023/10/27.
//
#include <stdio.h>
#include <math.h>

int IsPrime (int a);
int Roll (int x);

int main () {
    int n;
    scanf("%d",&n);
    int cnt = 0;  //初始算了2
    if (n >= 2) {
        cnt++;
    }
    for (int i = 3; i <= n; i += 2) {
        if (IsPrime(i)) {
            if(IsPrime(Roll(i))) {
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}

int IsPrime (int a) {
    int n = sqrt(a + 0.5);
    for (int i = 2; i <= n; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}
int Roll (int x) {  // x != 0
    int a[5] = {0};
    int cnt = 0;
    for (int i = 0; x > 0; i++) {
        a[i] = x % 10;
        x /= 10;
        cnt++;
    }
    for (int i = 0; i < cnt;i++) {
        x = x * 10 + a[i];
    }
    return x;
}

