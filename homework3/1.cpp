//
// Created by reprise on 2023/10/21.
//
#include<stdio.h>

#define MAX 100

int main() {
    int A[MAX][MAX], B[MAX][MAX], c[MAX][MAX];
    int m, n, p;

    scanf("%d%d%d", &m, &n, &p);
    for (int i = 0; i < m; i++) {        //读入A
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {        //读入B
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < m; i++) {          //进行乘法运算，获得矩阵c
        for (int j = 0 , sum = 0; j < p; j++) {  //这里似乎没有将sum清零？为什么？
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    //遍历输出
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
