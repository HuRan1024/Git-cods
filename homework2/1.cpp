//
// Created by reprise on 2023/10/14.
//
#include<stdio.h>
#include<string.h>
int main()
{
    /*给出一个长度为n 的字符串s，其中有些位置丢失了，这些位置用 ? 表示，已知这个串是一个回文字符串，请你在这些 ? 的位置填上相应的字符，还原这个字符串。

一个字符串被称为回文的，当且仅当它翻转之后所得的字符串与自己完全相同，比如 "1001"、"abcba" 都是回文的，而 "rikka" 不是回文的。*/
    char a[2000];
    int n;

    scanf("%d", &n);
    scanf("%s",a);
    for (int i = 0; i < strlen(a); i++){
        if(a[i] == '?'){
            a[i] = a[strlen(a) - 1 - i];
        }
    }
    printf("%s",a);
    return 0;
}