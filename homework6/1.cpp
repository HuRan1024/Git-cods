//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
int Do (int a,int b);

int main () {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d", Do(a,b));
    return 0;
}

int Do (int a, int b) {
    if (b == 1 || b == a) {
        return 1;
    }
    return Do(a - 1, b) + Do(a - 1, b - 1);
}