//
// Created by reprise on 2023/10/27.
//
#include <stdio.h>

#define MAX 2000

int main() {
    int a[MAX] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int len_max = 1, max_first = n - 1;
    for (int i = n - 1; i > 0; i--) {   //找到最大递减数列 (偏后者）
        if (a[i - 1] > a[i]) {
            len_max++;
            max_first--;
        } else {
            break;
        }
    }

    int min = a[max_first], min_position = max_first;
    if (max_first != 0) {
        for (int i = max_first; i < max_first + len_max; i++) { //找到递减数列中比之前一个数大的最小的数
            if (a[i] > a[max_first - 1] && a[i] < min) {
                min_position = i;
            }
        }

        int t = a[min_position];
        a[min_position] = a[max_first - 1];
        a[max_first - 1] = t;
    }

    for (int i = n - 1; i > n - len_max / 2 - 1; i--) {
        int t = a[i];
        a[i] = a[2 * n - len_max - 1 - i];
        a[2 * n - len_max - 1 - i] = t;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}