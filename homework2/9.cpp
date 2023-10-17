//
// Created by reprise on 2023/10/16.
//
#include <stdio.h>

#define MAX 1000000

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int l = 0, r = n - 1;
    int a[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pivot = a[k - 1], stop1 = 0, stop2 = 0, t;
    while (l <= r) {
        if (a[l] < pivot) {
            l++;
        } else {
            stop1 = 1;
        }
        if (a[r] >= pivot) {
            r--;
        } else {
            stop2 = 1;
        }
        if (stop1 == 1 && stop2 == 1) {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            stop1 = 0;
            stop2 = 0;
            l++;
            r--;
        }
    }

    int position = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == pivot) {
            position = i;
            break;
        }
    }
    if (l - 1 == r + 1 && stop1 != 1) {
        a[position] = a[l + 1];
        a[l + 1] = pivot;
    } else {
        a[position] = a[l];
        a[l] = pivot;
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}