//
// Created by reprise on 2023/10/8.
//
#include <stdio.h>
int main()
{
    int cnt = 0;
    int n;
    scanf("%d" ,&n);
    int max = n;
    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
        }else {
            n = 3 * n + 1;
        }
        if ( max < n) {
            max = n;
        }
        cnt ++;
    }
    printf ("%d %d",cnt,max);
    return 0;
}