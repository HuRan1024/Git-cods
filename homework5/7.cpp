
//
// Created by reprise on 2023/10/27.
//
/*#include <stdio.h>

#define MAX 1000000

int main() {
    int n,m,t,min;
    scanf("%d%d%d",&n,&m,&t);
    int a[MAX],b[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d",&b[i]);
    }

    min = t;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (t >= a[i] + b[j]) {
                if (min > t - a[i] - b[j]) {
                    min = t - a[i] - b[j];
                }
            } else {
                break;
            }
        }
    }
    if (min == t) {
        printf("-1");
    } else {
        printf("%d",min);
    }

    return 0;
} */

/*
#include <stdio.h>

#define MAX 1000

void Rank(int a[], int n);

int main() {
    int n;
    int m;
    int t;
    int min;
    scanf("%d%d%d", &n, &m, &t);
    int a[MAX], b[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    min = t;
    Rank(b, m);
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (j = 0; j < m; j++) {
            if (t >= a[i] + b[j]) {
                if (t - a[i] - b[j] < min) {
                    min = t - a[i] - b[j];
                }
            } else {
                break;
            }
        }
        if (j == 0) {
            break;
        }
    }

    if (min == t) {
        printf("-1");
    } else {
        printf("%d", min);
    }

    return 0;
}

void Rank(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}*/

#include <stdio.h>

#define MAX 1000000

int BinarySearch(int key, const int dict[], int len);

int main() {
    int n, m, t, min;
    scanf("%d%d%d", &n, &m, &t);
    int a[MAX], b[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    min = t;
    for (int j = 0; j < m; j++) {
        int i = BinarySearch(t - b[j], a, n);
        if (i >= 0) {
            if (a[i] <= t - b[j]) {
                if (t - b[j] - a[i] < min) {
                    min = t - b[j] - a[i];
                }
            } else {
                if (t - b[j] - a[i + 1] < min) {
                    min = t - b[j] - a[i + 1];
                }
            }
        }
    }

    if (min == t) {
        printf("-1");
    } else {
        printf("%d", min);
    }


    return 0;
}

int BinarySearch(int key, const int dict[], int len) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (key > dict[mid]) {
            low = mid + 1;
        } else if (key < dict[mid]) {
            high = mid - 1;
        } else {  // key == dictionary[mid]
            return mid;
        }
    }
    return low - 1;
}