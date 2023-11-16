//
// Created by reprise on 2023/10/27.
//
#include "stdio.h"

int Tool (int a,int n);

int main()
{
    int a;
    int n;
    scanf("%d %d",&n,&a);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += Tool(a,i);
    }
    printf("%d",sum);
    return 0;
}

int Tool (int a,int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum * 10 + a;
    }
    return sum;
}