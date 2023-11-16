////
//// Created by reprise on 2023/10/6.
////
//#include<stdio.h>
//#include <math.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//    /*int ch=1;
//    while((ch=getchar())!=EOF)
//    {
//        putchar(ch);
//    }
//    printf("EDF");*/
//    /*int a[2]={1};
//    for(int i=0;i<2;i++)
//    {
//        if(a[i]=='\0') printf("6");
//    }*/
//    /*int a[10],i;
//    for(i=0;i<10;i++)
//    {
//        printf("%d ",a[i]);
//    }*/
//    /*long long i = 0;
//    for ( i = 0; i >= 0; ){
//        i++;
//    }
//    printf("%ld" ,i);*/
////    int n;
////    scanf("%d",&n);
////    int a[n];
////    for (int i = 0; i < n; i++){
////        scanf("%d",&a[i]);
////    }
////    for (int i = 0; i < n; i++) {
////        for (int j = 0; j < n - i - 2; j++) {
////            if (a[j] > a[j + 1]) {
////                int tmp = a[j];
////                a[j] = a[j + 1];
////                a[j + 1] = tmp;
////            }
////        }
////    }
////    for (int i = 0; i < n; i++){
////        printf("%d ",a[i]);
////    }
//   /* char a[10];
//    scanf("%s",a);
//    int i = atoi(a);
//    printf("%d",i);*/
//
//    return 0;
//
//}
/*
#include<stdio.h>
#include<math.h>
int main ()
{
    int x,i = 1,sum = 0,k;
    for (x = 100000; x < 1000000; x++)
    {
        //x = 25;
        if (x == (int)sqrt(x) * (int)sqrt(x)){
            //printf("YES");
            k = x;
            while ( k > 0){
                sum = sum * 10 + k % 10;
                k /= 10;
            }
            if (sum == x){
                printf("%d\n",x);
            }
        }
    }
    return 0;
}*/
/*#include<stdio.h>
#include <math.h>
int main()
{
    double t,x,sum;
    int i = 2;
    scanf("%lf",&x);
    t = x;
    sum = x;
    while (fabs(t) >= 1e-8) {
        t = -t * x * x / i / (i + 1);
        sum += t;
        i += 2;
    }
    printf("%f",sum);
    return 0;
}*/
/*
#include<stdio.h>
int main ()
{
    int i = 0;
    int x1 = 2, x2 = 3;
    printf("%d %d ",x1,x2);
    for (i = 3; i < 21; i += 2) {
        x1 = x1 + x2;
        x2 = x2 - x1;
        printf("%d %d ",x1,x2);
    }
    return 0;
}*/
/*
#include <stdio.h>
#include <math.h>
int main()
{
    double x = 1, eps = 1e-7, x1, f1, f;
    do
    {
        x1 = x;
        f = cos(x1) - x1;
        f1 = -sin(x1) - x1;
        x = x1 - f / f1;
        f = cos(x) - x;
    } while (fabs(f) >= eps && fabs(x - x1) >= eps);
    printf("x=%.6f\nf(x)=%.6f\n", x,fabs(f));

    return 0;
}*/
/*
#include<stdio.h>
#include <math.h>
int main ()
{
    double a = -1, b = 1,eps = 1e-7,f,c;
    do {
        c = (a + b) / 2;
        f = exp(c) + c;
        if (fabs(f) < eps) {
            break;
        } else if (f > 0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs(a - b) >= eps);
    printf("x=%.6f",c);
    return 0;
}*/
