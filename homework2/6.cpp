//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>

#define MAX 50000
#define MAX1 100000

int main() {
    int T, n;
    int a[MAX], b[MAX1] = {0};    //利用b[]对每一组的判定结果储存
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {        //每次进行判定，a[n-1]是否为最大， 若是则为YES ，否则为NO
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        int max = a[n - 1];
        for (int j = 0; j < n; j++) {
            if (a[j] > max) {
                b[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < T; i++) {
        if (i != T - 1) {
            if (b[i] == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            if (b[i] == 0) {
                printf("Yes");
            } else {
                printf("No");
            }
        }

    }
    return 0;
}