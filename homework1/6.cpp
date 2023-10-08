//
// Created by reprise on 2023/10/8.
//
#include<stdio.h>
#define MAX 100001
int main()
{
    int n, tuo = 0,num;
    int a[MAX];
    scanf("%d",&n);
    for ( int i = 0; i < n+1; i++)
    {
        scanf("%d",&a[i]);
    }
    num = a[0];
    for (int i = 1; i < n+1; i++){
        if( num >= i){
            num += a[i];
        } else {
            tuo += i - num;
            num += a[i] + i - num ;
        }
    }
    printf("%d",tuo);
    return 0;
}