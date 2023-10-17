//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>
#include<string.h>

#define MAX 10000

int CHANGE(char a[])         //进制转换函数，转为平衡三进制并输出符号和结果（正）
{
    int ret = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == 'Z') {
            ret = ret * 3 - 1;
        } else if (a[i] == '0') {
            ret = ret * 3;
        } else if(a[i] == '1'){
            ret = ret * 3 + 1;
        }
    }
    return  ret;
}
/*int CHANGE (char a[])
{
    int ret = 0, i = 0;
    while (a[i] != '\0'){
        if (a[i] == 'Z'){
            ret = ret * 3 - 1;
        } else if (a[i] == '0'){
            ret = ret * 3;
        } else if (a[i] == '1'){
            ret = ret * 3 + 1;
        }
        i ++;
    }
    return ret;
}*/

int JUDGE(char a[]) {
    int ret = 0;                                  //判断是否合法
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != 'Z' && a[i] != '0' && a[i] != '1') {
            ret = 1;
            break;
        }
    }
    return ret;
}

/*int main() {
    char a[MAX][15];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (JUDGE(a[i])) {
            printf("Radix Error\n");
        } else {
            printf("%d\n", CHANGE(a[i]));
        }
    }
    return 0;
}*/
/*
 * 上面的main函数不正确，而下面的正确。
 * 是二维数组的问题，还是循环结构的问题？
 */
int main()
{
    int n;

    scanf("%d",&n);
    while(n--){
        char a[16];
        scanf("%s",a);
        if(JUDGE(a)){
            printf("Radix Error\n");
        } else {
            printf("%d\n", CHANGE(a));
        }
    }
    return 0;
}