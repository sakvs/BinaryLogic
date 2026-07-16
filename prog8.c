#include<stdio.h>
#define MAX 20

int a[MAX], x[MAX], target;

void subset(int sum, int pos, int rem)
{
    int i;

    x[pos] = 1;

    if(sum + a[pos] == target)
    {
        printf("Subset: ");

        for(i = 1; i <= pos; i++)
            if(x[i] == 1)
                printf("%d ", a[i]);

        printf("\n");
    }

    else if(sum + a[pos] + a[pos+1] <= target)
    {
        subset(sum + a[pos],
               pos + 1,
               rem - a[pos]);
    }

    if(sum + rem - a[pos] >= target &&
       sum + a[pos+1] <= target)
    {
        x[pos] = 0;

        subset(sum,
               pos + 1,
               rem - a[pos]);
    }
}

int main()
{
    int n, total = 0, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements in increasing order:\n");

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    if(total < target || a[1] > target)
        printf("No subset possible");
    else
        subset(0, 1, total);

    return 0;
}