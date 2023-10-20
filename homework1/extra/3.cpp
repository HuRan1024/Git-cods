//
// Created by reprise on 2023/10/10.
//
#include <stdio.h>
#include <string.h>

#define START 48

int main() {
    char a[1010], b[1010], c[1010] = {0};
    while(scanf("%s",a) != EOF && scanf("%s",b) != EOF){                //将两行的s分别赋给a,b；然后进行加算
        int n1 = strlen(a), n2 = strlen(b);
        //printf ("%d %d", n1, n2);
        int carry = 0, k = 0;
        int i, j;
        for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
            c[k] = (a[i] - START + b[j] - START + carry)  % 10 + START;
            carry = (a[i] - START + b[j] - START + carry) / 10;
            k = k + 1;
        }               //先加算所有能加的位数
        if (i == -1 && j == -1) {
            ;
        } else if (i == -1) {
            for (; j >= 0; j--) {
                c[k] = (b[j] + carry - START) % 10 + START;
                carry = (b[j] - START + carry) / 10;
                k++;
            }
        } else if (j == -1) {
            for (; i >= 0; i--) {
                c[k] = (a[i] + carry - START) % 10 +START;
                carry = (a[i] + carry - START) / 10;
                k++;
            }
        }            //再读取剩下的未加减的位数；
        if (carry == 1) {
            c[k] = 49;
            k++;
        }
        for (k = k - 1; k >= 0; k--) {
            printf("%c", c[k]);
        }
        printf("\n");
    }
    return 0;
}
