//
// Created by reprise on 2023/10/10.
//
#include <stdio.h>
#include <string.h>

#define START 48

int main() {
    char a[1001], b[1001], c[1001] = {0};
    char s[2002][1001];
    int n = 0;
    while (scanf ("%s",s[n]) != EOF){
        n ++;        //读入不定行，二维数组s中每一行为一个数
    }
    for (int p = 0; p <= n; p ++) {                   //将两行的s分别赋给a,b；然后进行加算
        for (int i = 0; i < 1001; i++) {
            a[i] = s[p][i];
        }
        p++;
        for (int i = 0; i < 1001; i++) {
            b[i] = s[p][i] ;
        }
        int n1 = strlen(a), n2 = strlen(b);
        //printf ("%d %d", n1, n2);
        int carry = 0, k = 0;
        int i, j;
        for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
            c[k] = (a[i] - START + b[j] - START) % 10 + carry + START;
            carry = (a[i] - START + b[j] - START) / 10;
            k = k + 1;
        }               //先加算所有能加的位数
        if (i == -1 && j == -1) {
            if (carry == 1) {
                c[k] = 49;
                k++;
            }
        } else if (i == -1) {
            c[k] = b[j] + carry;
            j--;
            k++;
            for (; j > 0; j--) {
                c[k] = b[j];
                k++;
            }
        } else if (j == -1) {
            c[k] = a[i] + carry;
            i--;
            k++;
            for (; i > 0; i--) {
                c[k] = a[i];
                k++;
            }
        }                 //再读取剩下的未加减的位数；
        for (k = k - 1; k >= 0; k--) {
            printf("%c", c[k]);
        }
        printf("\n");
    }
    return 0;
}
