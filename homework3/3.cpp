//
// Created by reprise on 2023/10/21.
//
#include <stdio.h>

#define SIZE 9
#define SMALL_SIZE 3

int JUDGE(char a[])  //输入一个含九个数的数组，判断其是否合格
{
    int min, k;
    int t = SIZE;
    /* for (int i = 0; i < t - 1; i++) {        //实现由小到大排序
        min = a[i];
        k = i;
        for (int j = i + 1; j < t; j++) {
            if (min > a[j]) {
                min = a[j];
                k = j;
            }
        }
        a[k] = a[i];
        a[i] = min;
    }*/
    /*for (int i = 0; i < t; i++) {
        printf("%d",a[i]);
    }
    printf("\n");*/
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < t; i++) {
        if (a[i] != i + 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char a[SIZE + 5][SIZE + 5];
    char b[SIZE + 5];
    int found = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            b[j] = a[i][j];
            //   printf("%d ",b[j]);
        }
        // printf("\n");
        found = JUDGE(b);
        if (found == 0) {
            printf("NO");
            return 0;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            b[j] = a[j][i];
            // printf("%d ",b[j]);
        }
        // printf("\n");
        found = JUDGE(b);
        if (found == 0) {
            printf("NO");
            return 0;
        }
    }
    int m;
    for (int i = 0; i < SIZE; i += SMALL_SIZE) {                  //i是起始点对应行
        for (int j = 0; j < SIZE; j += SMALL_SIZE) {            //j是起始点对应列
            m = 0;
            for (int k = 0; k < SMALL_SIZE; k++) {      //k是九宫格的行
                for (int l = 0; l < SMALL_SIZE; l++) {        //l是九宫格的列
                    b[m++] = a[i + k][l + j];
                    //printf("%d ",b[m - 1]);
                }
            }
            //printf("\n");
            found = JUDGE(b);
            if (found == 0) {
                printf("NO");
                return 0;
            }
        }
    }
    if(found == 1) {
        printf("YES");
    }
    return 0;
}