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

#include <stdio.h>

typedef struct competiters {
    int number;
    int score;
    int w;
} competiter;

void rank(competiter a[], int n) // 对选手，按分数从小到大排序
{
    int i, j, k;
    competiter t;

    for (i = 0; i < 2 * n; i++) {
        int max = a[i].score;
        k = i;
        for (j = i + 1; j < 2 * n; j++) {
            if (a[j].score >= max) {
                max = a[j].score;
                k = j;
            }
        }
        if (max == a[i].score) {
            if (a[k].number < a[i].number) {
                t = a[i];
                a[i] = a[k];
                a[k] = t;
            }
        } else {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}

int main() {
    int n, r, q, i, j;
    scanf("%d%d%d", &n, &r, &q);
    competiter a[200000];
    for (i = 0; i < 2 * n; i++) {
        a[i].number = i + 1;
    }
    for (i = 0; i < 2 * n; i++) {
        scanf("%d", &a[i].score);
    }
    for (i = 0; i < 2 * n; i++) {
        scanf("%d", &a[i].w);
    }
    rank(a, n);
    for (i = 0; i < r; i++) {
        for (j = 0; j < 2 * n; j += 2) {
            if (a[j].w > a[j + 1].w) {
                a[j].score++;
            } else {
                a[j + 1].score++;
            }
        }
        rank(a, n);
    }
    printf("%d", a[q - 1].number);
    return 0;
}