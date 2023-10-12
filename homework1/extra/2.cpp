//
// Created by reprise on 2023/10/9.
//
#include <stdio.h>
/*long long fact (long long n)
{
    long long ret= 1;
    for ( long long i = 1; i <= n; i++)
    {
        ret *= i;
        ret = ret % 1000000007;
    }
    return ret;
}*/
int main()
{
    long long  n , sum = 0;
    long long  x=1;
    scanf("%ld",&n);
    for ( long long i = 1; i <= n; i++)
    {
        x *= i ;
        x = x % 1000000007;
        sum += x % 1000000007;
        sum = sum % 1000000007;
    }

    printf ("%ld", sum);
    return 0;
}