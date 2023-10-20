//
// Created by reprise on 2023/10/17.
//
#include<stdio.h>
#include<string.h>
#include<math.h>

#define START 48

void EXCHANGE (char a[])  //翻转
{
    int i = 0, j = strlen(a) - 1;
    for (; i < j; i++, j--){
        char t;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

int ADD(char a[], char b[], char c[]) {                 //倒加倒得正，正加正得倒
    int n1 = strlen(a), n2 = strlen(b);
    //printf ("%d %d", n1, n2);
    int carry = 0, k = 0;
    int i, j;
    for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
        c[k] = (a[i] - START + b[j] - START + carry) % 10 + START;
        carry = (a[i] - START + b[j] - START + carry) / 10;
        k = k + 1;
    }               //先加算所有能加的位数
    if (i == -1 && j == -1) { ;
    } else if (i == -1) {
        for (; j >= 0; j--) {
            c[k] = (b[j] + carry - START) % 10 + START;
            carry = (b[j] - START + carry) / 10;
            k++;
        }
    } else if (j == -1) {
        for (; i >= 0; i--) {
            c[k] = (a[i] + carry - START) % 10 + START;
            carry = (a[i] + carry - START) / 10;
            k++;
        }
    }            //再读取剩下的未加减的位数；
    if (carry == 1) {
        c[k] = 49;
        k++;
    }
    return k;
}

int SUBTRACT(char a[], char b[], char c[]) {
    int n1 = strlen(a), n2 = strlen(b);
    //printf ("%d %d", n1, n2);
    int carry = 0, k = 0;
    int i, j;   // n1 >= n2
    for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
        if ((a[i] - b[j] + carry) >= 0) {
            c[k] = a[i] - b[j] + carry + START;
            carry = 0;
        } else {
            c[k] = a[i] - b[j] + carry + 10 + START;
            carry = -1;
        }
        k = k + 1;
    }               //先加算所有能加的位数
    if (i == -1 && j == -1) { ;
    } else if (j == -1) {
        for (; i >= 0; i--) {
            if (a[i] == START && carry == -1) {
                c[k] = 9 + START;
                carry = -1;
                k++;
            } else {
                c[k] = a[i] + carry;
                carry = 0;
                k++;
            }
        }
    }
    return k;
}

void MULTIPLY1(const char a[], char b, char c[],int j)  //实现单位数的乘法。 最后所得为一个正序的数组。j用于控制最后×10的j次方。
{
    int n1 = strlen(a);
    //printf ("%d %d", n1, n2);
    int carry = 0, k = 0;
    int i;

    for (i = n1 - 1; i >= 0; i--) {
        c[k] = ((a[i] - START) * b + carry) % 10 + START;
        carry = ((a[i] - START) * b + carry) / 10;
        k++;
    }
    if (carry != 0) {
        c[k++] = carry +START;
    }
    EXCHANGE(c);
    for(int p = 0; p < j; p++){
        c[k++] = '0';
    }
}

int MULTIPLY(char a[], char b[], char c[]) {
    int i = 0;
    int t = strlen(b);
    char e[10010];

    e[0] = '0';
    for(i = t - 1; i >= 0; i--){
        char d[10010] = {0};
        MULTIPLY1(a,b[i] - START,d,t - i - 1);
        ADD(e,d,c);
        EXCHANGE(c);
        strcpy(e,c);
    }
    return strlen(c);
}




int main() {
    char a[10010], b[10010], c[10010] = {0};
    char op;
    int k = 0;
    while (scanf("%s", a) != EOF && scanf(" %c", &op) != EOF && scanf("%s", b) != EOF) {
        switch (op) {
            case '+':
                k = ADD(a, b, c);
                for (k = k - 1; k >= 0; k--) {
                    printf("%c", c[k]);
                }
                printf("\n");
            case '-':
                k = SUBTRACT(a, b, c);
                k--;
                if (c[k] == '0') {
                    for (k = k - 1; k > 0 && c[k] == START; k--) {}
                }
                for (; k >= 0; k--) {
                    printf("%c", c[k]);
                }
                printf("\n");
            case '*':
                MULTIPLY(a,b,c);
                printf("%s\n",c);
        }
    }
    return 0;
}