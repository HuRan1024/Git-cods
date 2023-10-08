//
// Created by reprise on 2023/10/8.
//
#include<stdio.h>
#define MAX 10000000
int main()
{
    int k,n,ch;
    char a[MAX];
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%c",&a[i]);
        while (a[i]=='\n'){
            scanf("%c",&a[i]);
        }
    }
    scanf("%d",&k);
    for ( int i = k - 1; i >= 0; i--){
        printf("%c",a[i]);
    }
    for ( int i = n - 1; i >= k; i--){
        printf("%c",a[i]);
    }
    return 0;
}