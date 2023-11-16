///*
////
//// Created by reprise on 2023/10/15.
////
//#include<stdio.h>
//#include<math.h>
//
//int mypow(int x, int y) {
//    int f = 1, i;
//    if (y == 0) {
//        f = 1;
//    } else {
//        for (i = 1; i <= y; i++) {
//            f *= x;
//        }
//    }
//    return f;
//}
//
//int main() {
//    int i, r, x, y, s, count, count1;
//    printf("0 ");
//    for (i = 1; i <= 200000; i++) {
//        i = 25;
//        r = i, s = 0, x = 10, y = 1, count = 1, count1 = 0;
//        for (count1 = 0; r > 0; count1++) {       //求位数
//            r = r / 10;
//        }
//        for (count = 1; count <= count1; count++) {
//            s += ((i % x) / y) * i % (mypow(10, count1 - count + 1)) * (mypow(10, count - 1));
//            x *= 10, y *= 10;
//        }
//        if (i == s) {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}*/
//#include<stdio.h>
//int main()
//{
//    char xs[4];
//    int i,a,b,c,d;
//    xs[0]='A';xs[1]='B';xs[2]='C';xs[3]='D';
//    char t;
//    for(i=0;i<4;i++){
//        t=xs[i];
//        if(t!='A')
//            a=1;
//        if(t=='C')
//            b=1;
//        if(t=='D')
//            c=1;
//        if(t!='D')
//            d=1;
//        if(a+b+c+d==3){
//            printf("%c打烂了玻璃",t);
//            break;}
//    }
//    return 0;
//}
//#include<stdio.h>
//
//int main() {
//    int n, i, A, j, count1 = 0, k, count2 = 0;
//    scanf("%d", &n);
//    int a[50000], count[50000] = {0};
//    for (i = 0; i <= n - 1; i++) {
//        scanf("%d", &a[i]);
//    }
//    for (i = 0; i <= n - 1; i++) {
//        if (a[i] != -1) {
//            A = a[i];
//            for (j = i + 1; j <= n - 1; j++) {
//                if (a[j] == A) {
//                    a[j] = -1;
//                    count[A]++;
//                }
//            }
//        }
//    }
//    for (k = 0; k < 50000; k++) {
//        if (count[k] != 0) {
//            count2 = count1 = count[k];
//            break;
//        }
//    }
//    for (k = k + 1; k < 50000; k++) {
//        if (count[k] != 0) {
//            count2 = count1 > count[k] ? count1 : count[k];
//        }
//    }
//    for (k = 0; k < 50000; k++) {
//        if (count[k] == count2) {
//            printf("%d\n%d", k, count2 + 1);
//        }
//    }
//    return 0;
//}
/*
#include<stdio.h>

int function(int x) {
    int sum = 0, y, x1;
    x1 = x;
    while (x1 > 0) {
        y += x1 % 10;
        y *= 10;
        x1 /= 10;
    }
    y /= 10;
    sum = x + y;
    return sum;
}

int judge(int x) {
    int x1, y = 0;
    x1 = x;
    while (x1 > 0) {
        y += x1 % 10;
        y *= 10;
        x1 /= 10;
    }
    y /= 10;
    if (y == x)
        return 1;
    return 0;
}

int main() {
    int L, count, b;
    scanf("%d", &L);
    int array[L], ans[L] = {0};
    for (int i = 0; i < L; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < L; i++) {
        b = array[i];
        for (count = 1; count <= 8; count++) {
//            printf("%d ",b);
            b = function(b);
            printf("%d\n", b);
            if (judge(b)) {
                ans[i] = count;
                break;
            }
        }
    }
    for (int i = 0; i < L; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100
#define MAX(a, b) (a > b ? a : b)
#define DO 10000

int main() {
    double result = 0;
    int a[100] = {0};
    srand(time(NULL));  //生成随机数列

    for (int i = 0; i < 50; i++) {
        int flag = 1;
        int x, y;
        while (flag) {  //取不重复数x,y
            x = rand() % RANGE + 1;   //取随机数，范围1-RANGE（100）
            y = rand() % RANGE + 1;
            for (int j = 0; j < 50; j++) {
                if (x == a[j] || y == a[j]) {
                    continue;
                } else {
                    flag = 0;
                }
            }
        }
        // printf("%d %d \n", x, y);  //测试语句
        a[i] = MAX(x, y);
    }
    int num = 0;
    for (int i = 0; i < 50; i++) {
        if (a[i] > RANGE / 2) {
            num++;
        }
    }
    printf("%d\n", num);
    result += num * 1.0 / RANGE;
    return 0;
}*/
/*
#include<stdio.h>
#include<stdlib.h>

#define MAX_STRLEN 256

int next[MAX_STRLEN];

typedef struct {
    char str[MAX_STRLEN];
    int length;
} StringType;

typedef struct {
    char *ch;
    int length;
} HString;

HString *HStrAssign(HString *S, char *chars) {
    int len = 0, i;
    char *p = chars;
    while (*p != '\0') {
        len++;
        p++;
    }
    S = (HString *) malloc(sizeof(HString));
    S->ch = (char *) malloc(len * (sizeof(char)));
    if (!S || !S->ch) {
        printf("分配空间失败！");
        exit(0);
    }
    S->length = len;
    p = chars;
    for (i = 0; i < len; i++)
        S->ch[i] = chars[i];
    return S;
}

void HStrDestroy(HString *S) {
    free(S->ch);
}

void HStrClear(HString *S) {
    S->length = 0;
    free(S->ch);
}

int HStrLength(HString *S) {
    return S->length;
}

void Next(HString *S) {
    int i = 2, j;
    next[0] = -1;
    next[1] = 0;
    while (i < S->length) {
        j = next[i - 1];
        while (j > 0 && S->ch[j] != S->ch[i - 1])
            j = next[j];
        if (j <= 0) {
            if (S->ch[0] == S->ch[i - 1])
                next[i] = 1;
            else
                next[i] = 0;
        } else
            next[i] = j + 1;
        i++;
    }
}

int KMP_Index(HString *S, HString *T, int pos) {
    int i = pos, j = 0;
    Next(T);
    while (i < S->length && j < T->length) {
        if (j == -1 || S->ch[i] == T->ch[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j >= T->length)
        return i - T->length;
    else
        return -1;
}

void *HSubString(HString *Sub, HString *S, int pos, int len) {
    int i = pos, j = 0;
    Sub->length = len;
    Sub->ch = (char *) malloc(len * (sizeof(char)));
    for (j = 0; j < len; i++, j++)
        Sub->ch[j] = S->ch[i];
}

void Replace(HString *S, HString *T, HString *V) {
    int pos = 0, i, Delta;
    while (KMP_Index(S, T, pos) != -1) {
        pos = KMP_Index(S, T, pos);
        if (T->length > V->length) {
            Delta = T->length - V->length;
            for (i = 0; i < V->length; i++)
                S->ch[i + pos] = V->ch[i];
            for (i = pos + V->length; i < S->length; i++)
                S->ch[i] = S->ch[i + Delta];
            pos = pos + V->length;
            S->ch = (char *) realloc(S->ch, (S->length - Delta) * (sizeof(char)));
            S->length -= Delta;
        }
        if (T->length == V->length) {
            for (i = 0; i < V->length; i++)
                S->ch[i + pos] = V->ch[i];
            pos = pos + V->length;
        }
        if (T->length < V->length) {
            Delta = V->length - T->length;
            if (S->length + Delta > MAX_STRLEN) {
                printf("超出串最大长度！");
                exit(0);
            }
            S->ch = (char *) realloc(S->ch, (S->length + Delta) * (sizeof(char)));
            for (i = S->length - 1; i >= pos + T->length; i--)
                S->ch[i + Delta] = S->ch[i];
            for (i = 0; i < V->length; i++)
                S->ch[i + pos] = V->ch[i];
            pos = pos + V->length;
            S->length += Delta;
        }
    }
}

void HStringConcat(HString *S1, HString *S2) {
    int i;
    if (S1->length + S2->length > MAX_STRLEN) {
        printf("超出串最大长度！");
        exit(0);
    }
    S1->ch = (char *) realloc(S1->ch, (S1->length + S2->length) * (sizeof(char)));
    for (i = 0; i < S2->length; i++)
        S1->ch[i + S1->length] = S2->ch[i];
    S1->length += S2->length;
}

void HStringPrint(HString *S) {
    int i;
    for (i = 0; i < S->length; i++) {
        putchar(S->ch[i]);
    }
}

int main() {
    HString *S, *T, *V;
//	HString s,t,v;
//	S=&s,T=&t,V=&v;
    char a[] = "AABAAA", b[] = "AA", c[] = "ABC";
    HStrAssign(S, a);
    HStrAssign(T, b);
    HStrAssign(V, c);
    Replace(S, T, V);
    HStringConcat(S, T);
    HStringPrint(S);
    return 0;
}
*/

