//
// Created by reprise on 2023/10/9.
//
#include <stdio.h>
int TOOL ( long long a, long long b)
{
    long long i;
    while (b != 0)
    {
        i = b;
        b = a % b;
        a = i;
    }
    if ( a == 1){
        return 1 ;
    } else {
        return 0;
    }
}
int main ()
{
    long long cnt = 1, n, x =2;
    scanf ( "%ld",&n);
    for (long long i = 3; i <= n; i = i+2){
        if (x > i){
            if (TOOL (x,i)){
                x *= i;
                cnt ++;
                printf ("%ld\n",i);
            }
        } else {
            if (TOOL (i,x)){
                x *= i;
                cnt ++;
            }
        }
    }
    printf ( "%ld", cnt);
    return 0;
}
