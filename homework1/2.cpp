//
// Created by reprise on 2023/10/8.
//
#include<stdio.h>
int fact(int n)
{
    int ret = 1;
    for(int i = 1; i <= n; i++)
    {
        ret *= i;
        ret = ret % 10007;
    }
    return ret;
}
int main()
{
    int n;
    int sum = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        sum += fact (i) ;
    }
    sum = sum % 10007;
    printf ("%d",sum);
    return 0;
}