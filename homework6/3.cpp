//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
#define MAX 100005
int a[MAX];
int Find (int a[],int i);

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", Find(a,i));
    }
    return 0;
}

int Find (int a[],int i) {
    if (a[i] == i + 1) {
        return i + 1;
    }
    return Find(a,a[i] - 1);

}
