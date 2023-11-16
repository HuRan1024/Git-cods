//
// Created by reprise on 2023/10/29.
//
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int CHANGE1(char a[]);      //进制转换函数，转为平衡三进制并输出符号和结果（正）  三转十
void CHANGE2(int sum, char a[]);   //十转三

char a[25], b[25], ans[25];

int main() {
    int n;
    char m, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c/%c", &m, &t);
        scanf("%s %s", a, b);
        int ans_t;
        if (m == 'p') {
            ans_t = CHANGE1(a) + CHANGE1(b);
        } else if (m == 'm') {
            ans_t = CHANGE1(a) - CHANGE1(b);
        }
        if (t == 'd') {
            printf("%d", ans_t);
        } else if (t == 't') {
            CHANGE2(ans_t, ans);
            int len = strlen(ans);
            for (int i = len - 1; i >= 0; i--) {
                printf("%c", ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

void CHANGE2(int sum, char a[]) {
    int sign = 0;
    if (sum < 0) {
        sign = 1;
        sum = -sum;
    }
    int j = 0;
    for (; sum > 0; j++) {
        a[j] = sum % 3 + '0';          //三进制转化（倒序）
        sum /= 3;
    }
    a[j] = 0;
    a[j + 1] = 0;
    int t = strlen(a);
    for (int i = 0, carry = 0; i <= t; i++) {
        if (a[i] != 0) {
            a[i] += carry;
            if (a[i] == '2') {
                a[i] = 'Z';
                carry = 1;
            } else if (a[i] == '3') {
                a[i] = '0';
                carry = 1;
            } else {
                carry = 0;
            }
        } else if (carry == 1) {
            a[i] = '1';
        }
    }
    if (sign == 1) {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == '1') {
                a[i] = 'Z';
            } else if (a[i] == 'Z') {
                a[i] = '1';
            }
        }
    }
}

int CHANGE1(char a[]) {
    int ret = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == 'Z') {
            ret = ret * 3 - 1;
        } else if (a[i] == '0') {
            ret = ret * 3;
        } else if (a[i] == '1') {
            ret = ret * 3 + 1;
        }
    }
    return ret;
}