//
// Created by reprise on 2023/10/5.
//
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int a[N-1],i,j;
    for(i=0;i<(N-1);i++)
    {
        a[i]=i+2;
    }
    for(i=0;i<N;i++)
    {
        if(a[i]!=0)
        {
            printf("%d\n",a[i]);
            for(j=2;j*(i+2)<=N;j++)
            {
                a[j*(i+2)-2]=0;
            }
        }
    }
    return 0;
}