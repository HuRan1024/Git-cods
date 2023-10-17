//
// Created by reprise on 2023/10/15.
//
#include<stdio.h>
#include<string.h>

int JUDGE(int N, char a[]) {
    int ret = 0;
    if (N <= 10) {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] >= N + '0') {
                ret = 1;
                break;
            }
        }
    } else if (N <= 16) {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] >= N - 10 + 'A') {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int CHANGE(int N, int len, char a[]) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] <= '9' && a[i] >= '0') {
            ret = ret * N + a[i] - '0';
        } else if (a[i] >= 'A' && a[i] <= 'F') {
            ret = ret * N + a[i] - 'A' + 10;
        }
    }
    return ret;
}

int main() {
    int len, N;
    scanf("%d%d", &len, &N);
    char a[30];
    scanf("%s", a);
    if (JUDGE(N, a)) {
        printf("Error\n");
    } else {
        printf("%d", CHANGE(N, len, a));
    }
    return 0;
}