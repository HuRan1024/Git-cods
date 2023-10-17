//
// Created by reprise on 2023/10/7.
//
//#include<stdio.h>
//
//void rank(int a[], int s[], const int N, int w[])//排列函数，a[i]的值是名次为i-1的人
//{
//    int i = 0, j = 0;
//    int min, t;
//    for (j = 0; j < 2 * N; j++) {
//        min = j;
//        for (i = j + 1; i < 2 * N; i++) {
//            //printf("%d %d",a[j],b[a[j]]);
//            if (s[i] > s[j]) {
//                min = i;
//            }
//        }      //找到分数最高的人
//        t = s[j];
//        s[j] = s[min];
//        s[min] = t;
//        t = a[min];
//        a[min] = a[j];
//        a[j] = t;
//        t = w[min];
//        w[min] = w[j];
//        w[j] = t;
//    }
//}
//
//int main() {
//    int N, R, Q;
//    scanf("%d%d%d", &N, &R, &Q);
//    int a[2 * N], s[2 * N], w[2 * N], i, j;
//    for (i = 0; i < 2 * N; i++) {
//        scanf("%d", &s[i]);
//    }
//    for (i = 0; i < 2 * N; i++) {
//        scanf("%d", &w[i]);
//    }
//    for (i = 0; i < 2 * N; i++) {
//        a[i] = i;
//    }
//    rank(a, s, N, w);
//    for (j = 0; j < R; j++) {
//        for (i = 0; i < N; i++) {
//            if (w[2 * i] > w[2 * i + 1]) {
//                s[2 * i]++;
//            } else
//                s[2 * i + 1]++;
//        }
//        rank(a, s, N, w);
//        /*for(i=0;i<2*N;i++)
//        {
//            printf("%d %d  ",a[i],s[i]);
//        }
//        printf("\n");*/
//    }
//    printf("%d", a[Q - 1] + 1);
//    /*for(i=0;i<2*N;i++)
//    {
//        printf("%d %d  ",a[i],s[i]);
//    }*/
//    return 0;
//}
//
// Created by reprise on 2023/10/7.
//
#include<stdio.h>

void rank(int a[], int s[], int N)//排列函数，a[i]的值是名次为i的选手的序号-1
{
    int i = 0, j = 0;
    int b[2 * N];
    for (i = 0; i < 2 * N; i++) {
        b[i] = s[i];
        //printf("%d ",b[i]);
    }
    for (j = 0; j < 2 * N; j++) {
        for (i = 0; i < 2 * N; i++) {
            //printf("%d %d",a[j],b[a[j]]);
            if (b[i] > b[a[j]]) {
                a[j] = i;
            }
        }
        b[a[j]] = 0;
    }
}

int main() {
    int N, R, Q;
    scanf("%d%d%d", &N, &R, &Q);
    int a[2 * N], s[2 * N], w[2 * N], i, j;
    for (i = 0; i < 2 * N; i++) {
        scanf("%d", &s[i]);
    }
    for (i = 0; i < 2 * N; i++) {
        scanf("%d", &w[i]);
    }
    for (i = 0; i < 2 * N; i++) {
        a[i] = i;
    }
    rank(a, s, N);
    for (j = 0; j < R; j++) {
        for (i = 0; i < N; i++) {
            if (w[a[2 * i]] > w[a[2 * i + 1]]) {
                s[a[2 * i]]++;
            } else
                s[a[2 * i + 1]]++;
        }
        rank(a, s, N);
        /*for(i=0;i<2*N;i++)
        {
            printf("%d %d  ",a[i],s[i]);
        }
        printf("\n");*/
    }
    printf("%d", a[Q - 1] + 1);
/*for(i=0;i<2*N;i++)
{
    printf("%d %d  ",a[i],s[i]);
}*/
    return 0;
}