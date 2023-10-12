//
// Created by reprise on 2023/10/5.
//
#include <stdio.h>
#include <math.h>
/*int TOOL ( long long a, long long b)
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
}*/
int main()
{
    long long N;
    scanf("%ld",&N);
    int a[1300],i,j,ret,n=1;
    a[0]=2;
    //printf("%d\n",a[0]);
    if ( N <= 10000){
        for(i=3;i<=N; i += 2)
        {
            ret = 1;
            for(j=0;j<n;j++)   // 这里用j<n可正常运行，而使用a[j]<i则无法正常运行,why?
            {
                if(i%a[j]==0 ){
                    ret=0;
                    break;
                }
            }
            if(ret==1)
            {
                a[n]=i;
                //printf("%d %d\n",i,a[n]);
                n+=1;
            }
        }
    } else {
        for (i = 3; i <= 10000; i += 2) {
            ret = 1;
            for (j = 0; j < n; j++)   // 这里用j<n可正常运行，而使用a[j]<i则无法正常运行,why?
            {
                if (i % a[j] == 0) {
                    ret = 0;
                    break;
                }
            }
            if (ret == 1) {
                a[n] = i;
                //printf("%d %d\n",i,a[n]);
                n += 1;
            }
        }
        for (i = 10001; i <= N; i += 2) {
            ret = 1;
            for (j = 0; j < 1229; j++)   // 这里用j<n可正常运行，而使用a[j]<i则无法正常运行,why?
            {
                if (i % a[j] == 0) {
                    ret = 0;
                    break;
                }
            }
            if (ret == 1) {
                //printf("%d %d\n",i,a[n]);
                n += 1;
            }
        }
    }
    printf ( "%d",n);
    return 0;
}