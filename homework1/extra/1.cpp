//
// Created by reprise on 2023/10/9.
//

#include <stdio.h>

int main() {

    int a, b = 0, c = 0, d = 0, e = 0, f = 0;
    int cnt = 0;
    int i = 0;
    scanf("%d", &a);
    if (a == 0) {
        printf("位数:1\n每位数字为:0\n反序数字为:0");
    } else {
        if (a != 0) {
            b = a % 10;
            a /= 10;
            cnt++;
        }
        if (a != 0) {
            c = a % 10;
            a /= 10;
            cnt++;
        }
        if (a != 0) {
            d = a % 10;
            a /= 10;
            cnt++;
        }
        if (a != 0) {
            e = a % 10;
            a /= 10;
            cnt++;
        }
        if (a != 0) {
            f = a % 10;
            a /= 10;
            cnt++;
        }
        printf("位数:%d\n", cnt);
        printf("每位数字为:");
        if (f != 0) {
            printf("%d", f);
        }
        if (e != 0 && cnt == 4) {
            printf("%d", e);
        } else if (e != 0) {
            printf(",");
            printf("%d", e);
        }
        if (d != 0 && cnt == 3) {
            printf("%d", d);
        } else if (d != 0) {
            printf(",");
            printf("%d", d);
        }
        if (c != 0 && cnt == 2) {
            printf("%d", c);
        } else if (c != 0) {
            printf(",");
            printf("%d", c);
        }
        if (b != 0 && cnt == 1) {
            printf("%d", b);
        } else if (b != 0) {
            printf(",");
            printf("%d", b);
        }
        int sum = b;
        if (c != 0) {
            sum = sum * 10 + c;
        }
        if (d != 0) {
            sum = sum * 10 + d;
        }
        if (e != 0) {
            sum = sum * 10 + e;
        }
        if (f != 0) {
            sum = sum * 10 + f;
        }
        printf("\n反序数字为:%d", sum);
    }
    return 0;
}
/*#include <stdio.h>
int main()
{
char a[10];
int n = 0;
int i = 0;
while ((a[i]=getchar()) != '\n')
{
    i++;
}
n = i;
printf("位数：%d\n每位数字为：", i);
for (i = 0; i <= n; i++)
{
    putchar(a[i]);
    if (i < n-1)
        printf(",");
}
printf("反序数字为：");
for (i = n - 1; i >= 0; i--)
{
    putchar(a[i]);
}
return 0;
}*/