//
// Created by reprise on 2023/10/22.
//
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d",&n);
    char a[MAX + 6],b[MAX + 6];   //a为原来的，b为变化后的
    scanf("%s",a);
    // printf("%s",b);
    int t = strlen(a);
    for (int i = t + 2; i >= 3; i--) {     //实现扩展数组的初始化，扩展出的额外位为0
        a[i] = a[i - 3];
        // printf("%c",a[i]);
    }
    a[0] = '.';
    a[1] = '.';
    a[2] = '.';
    strcpy(b,a);
    for (int i = 0; i < n; i++) {       //循环总轮数
        for (int j = 3; j < t + 3; j++) {
            int num_a = 0, num_b = 0;
            for (int k = 3; k > 0; k--) {
                if (a[j - k] == 'A') {
                    num_a++;
                } else if (a[j - k] == 'B') {
                    num_b++;
                }
                if (a[j + k] == 'A') {
                    num_a++;
                } else if (a[j + k] == 'B') {
                    num_b++;
                }
            }
            if (a[j] == '.') {        //实现一轮的变化
                if (num_a <= 4 && num_a >= 2 && num_b == 0) {
                    b[j] = 'A';
                } else if (num_b <= 4 && num_b >= 2 && num_a == 0) {
                    b[j] = 'B';
                }
            }
            if (a[j] == 'A') {
                if (num_b || num_a >= 5 || num_a <= 1) {
                    b[j] = '.';
                }
            }
            if (a[j] == 'B') {
                if (num_a || num_b >= 5 || num_b <= 1) {
                    b[j] = '.';
                }
            }
        }
        strcpy(a,b);  //把新版赋给旧版
        /*for (int p = 3; p < t + 3; p++) {
            printf("%c",a[p]);
        }
        printf("\n");*/
    }
    for (int i = 3; i < t + 3; i++) {
        printf("%c",a[i]);
    }

    return 0;
}