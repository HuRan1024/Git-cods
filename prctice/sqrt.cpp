//
// Created by reprise on 2023/10/6.
//
#include<stdio.h>
#include<math.h>
int main()
{
    double X,X1,X2,differ=1;
    scanf("%lf",&X);
    X1=X;
    while(differ>=0.00001)
    {
        X2=1.0/2*(X1+X/X1);
        differ=fabs(X2-X1);
        X1=X2;
    }
    printf("%.3f",X1);
    return 0;
}