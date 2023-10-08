//
// Created by reprise on 2023/10/5.
//
#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int a[N],i,j,ret,n=1;
    a[0]=2;
    printf("%d\n",a[0]);
    for(i=3;i<=N;i++)
    {
        ret=1;
        for(j=0;j<n;j++)   // 这里用j<n可正常运行，而使用a[j]<i则无法正常运行,why?
        {
            if(i%a[j]==0){
                ret=0;
            }
        }
        if(ret==1)
        {
            a[n]=i;
            printf("%d %d\n",i,a[n]);
            n+=1;
        }
    }
    return 0;
}