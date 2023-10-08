//
// Created by reprise on 2023/10/8.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    double x,y = 0;
    scanf("%lf %d",&x,&n);
    for (int i = 0; i <= n; i++)
    {
        y += pow (-1,i) * pow (x,2*i+1)/(2 * i + 1);
    }
    y *= 4;
    printf("%.10f",y);
    return 0;
}