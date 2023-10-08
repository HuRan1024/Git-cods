//
// Created by reprise on 2023/10/7.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int P,N;
    scanf("%d %d",&P,&N);
    int min1=1,min2=1,max1=N,max2=1;
    int a[N],b[N],i,j;
    for(i=0;i<N;i++)
    {
        a[i]=i+1;
        b[i]=i+1;
    }
    for(i=0;i<N;i++)
    {
        for(j=(int)((i+1)*(min1*1.0/min2));j<N;j++)
        {
            if(a[j]*1.0/b[i]>sqrt(P))
            {
                break;
            }else
            {
                min1=a[j];min2=b[i];
            }
        }
    }
    for(i=0;i<N;i++)
    {

        for(j=(int)(sqrt(P)*(i+1));j<N;j++)
        {
            double tool=max1*1.0/max2;
            if(a[j]*1.0/b[i]<tool)
            {
                max1=a[j];max2=b[i];
                break;
            }
        }
    }
    printf("%d/%d %d/%d",min1,min2,max1,max2);
    return 0;
}