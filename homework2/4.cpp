////
//// Created by reprise on 2023/10/14.
////
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//#include<stdlib.h>
//
//#define MAX 10000
//
//int JUDGE(char a[]) {
//    int ret = 0;                                  //判断是否合法
//    for (int i = 0; i < strlen(a); i++) {
//        if (isdigit(a[i]) == 0 && a[i] != '-') {
//            ret = 1;
//        }
//    }
//    return ret;
//}
//
//void CHANGE(char a[]) {
//    int sum = 0;
//    int sign = 0;
//    if (a[0] == '-') {
//        sign = 1;
//    } else {
//        sum = sum * 10 + a[0] - '0';
//    }
//    for (int i = 1; i < strlen(a); i++) {
//        sum = sum * 10 + a[i] - '0';
//    }
//    for (int i = 0; sum > 0; i++) {
//        a[i] = sum % 3 + '0';
//        sum /= 3;
//    }
//    int t = strlen(a);
//    for (int i = 0, carry = 0; i <= t; i++) {
//        if (a[i] != 0) {
//            a[i] += carry;
//            if (a[i] == '2') {
//                a[i] = 'Z';
//                carry = 1;
//            } else if (a[i] == '3') {
//                a[i] = '0';
//                carry = 1;
//            }
//        } else if (carry == 1) {
//            a[i] = '1';
//        }
//    }
//    if (sign == 1) {
//        for (int i = 0; i < strlen(a); i++) {
//            if (a[i] == '1') {
//                a[i] = 'Z';
//            } else if (a[i] == 'Z') {
//                a[i] = '1';
//            }
//        }
//    }
//}
//
//int main() {
//    char a[MAX][22];
//    int n;
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%s", a[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        if (JUDGE(a[i]) && i != n - 1) {
//            printf("Radix Error\n");
//        } else if (JUDGE(a[i]) && i == n - 1) {
//            printf("Radix Error");
//        } else {
//            CHANGE(a[i]);
//            for (int j = strlen(a[i]) - 1; j >= 0; j--) {
//                printf("%c", a[i][j]);
//            }
//            if (i < n - 1) {
//                printf("\n");
//            }
//        }
//    }
//    return 0;
//}
//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 10000

int JUDGE(char a[]) {
    int ret = 0;                                  //判断是否合法
    for (int i = 0; i < strlen(a); i++) {
        if (isdigit(a[i]) == 0 && a[i] != '-') {
            ret = 1;
        }
    }
    return ret;
}

void CHANGE(char a[]) {
    int sum = 0;
    int sign = 0;
    sum = atoi(a);   //转为十进制
    if (sum < 0) {
        sign = 1;
        sum = -sum;
        a[1] = 0;
    }
    for (int i = 0; sum > 0; i++) {
        a[i] = sum % 3 + '0';          //三进制转化（倒序）
        sum /= 3;
    }
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

/*int main() {
    char a[MAX][22];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (JUDGE(a[i]) && i != n - 1) {
            printf("Radix Error\n");
        } else if (JUDGE(a[i]) && i == n - 1) {
            printf("Radix Error");
        } else {
            CHANGE(a[i]);
            for (int j = strlen(a[i]) - 1; j >= 0; j--) {
                printf("%c", a[i][j]);
            }
            if (i < n - 1) {
                printf("\n");
            }
        }
    }
    return 0;
}*/

int main() {
    int n;

    scanf("%d", &n);
    while (n--) {
        char a[21] = {0};
        scanf("%s", a);
        if (JUDGE(a)) {
            printf("Radix Error\n");
        } else {
            CHANGE(a);
            for (int i = strlen(a) - 1; i >= 0; i--) {
                printf("%c", a[i]);
            }
            printf("\n");
        }
    }

    return 0;
}