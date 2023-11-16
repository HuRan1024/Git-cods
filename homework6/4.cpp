//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
int nums[100005];
int result[100005][2];
int FindMax (const int a[],int low,int high) {
    int max = a[low];
    int index = low;
    for (int i = low; i <= high; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return index;
}
void Do (const int a[],int b[][2],int low,int high) {
    if (low == high) {
        b[low][0] = b[low][1] = low;
        return;
    }
    if (low > high) {
        return;
    }
    int index = FindMax(a,low,high);
    b[index][0] = low;
    b[index][1] = high;
    Do(a,b,low,index - 1);
    Do(a,b,index + 1,high);
    return;
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&nums[i]);
    }
    Do(nums,result,0,n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n",result[i][0] + 1,result[i][1] + 1);
    }

    return 0;
}