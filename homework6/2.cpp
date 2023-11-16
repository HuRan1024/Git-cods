//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
int Do (int n);

int main () {
    int n;
    scanf("%d",&n);
    printf("%d", Do(n));
    return 0;
}

int Do (int n) {
    if (n <= 1) {
        return 1;
    }
    return Do(n - 1) + Do(n - 2);

}