#include <stdio.h>
int main()
{
    int n, number;
    int a[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        scanf("%d", &number);
        a[number - 1]++;
    }
    for (int i; i < 1000; i++)
    {
        if (a[i] == 1)
        {
            printf("%d", i + 1);
        }
    }
    return 0;
}