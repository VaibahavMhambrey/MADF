#include <stdio.h>
#define MAX 9
int a[MAX];

void minmax(int i, int j, int *max, int *min)
{
    int mid, max1, min1;
    if (i == j)
    {
        *max = a[i];
        *min = a[i];
        //printf("max is %d\n", *max);
        //printf("min is %d\n", *min);
        return;
    }
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
        //printf("max is %d\n", *max);
        //printf("min is %d\n", *min);
        return;
    }
    else
    {
        mid = (i + j) / 2;
        minmax(i, mid, max, min);
        minmax(mid + 1, j, &max1, &min1);
        if (max1 > *max)
            *max = max1;
        if (min1 < *min)
            *min = min1;
    }
}

int main()
{
    int i,n, min = 0, max = 0;
    printf("give numbers\n");
    for (i = 0; i <9; i++)
    {
        scanf("%d ", &a[i]);
    }
    minmax(0, 8, &max, &min);
    printf("max is %d\n", max);
    printf("min is %d\n", min);
}
