//character array

#include<stdio.h>
#define MAX 12


int partition(char a[MAX], int low, int high)
{
    char p=a[low], temp;
    int i=low+1, j=high;
    while (i<=j){
        while (a[i]<=p && i<=high)
            i=i+1;
        while (a[j]>p)
            j=j-1;
        if (i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=i+1;
            j=j-1;
        }
        else    i=i+1;
    }
    a[low]=a[j];
    a[j]=p;
    printf("j=%d\n", j);
    return j;
}

char KthSmallest(char a[MAX], int n, int k)
{
    k=k+1;
    int low=1, up=n+1, j;
    while (1)
    {
        j=partition(a, low, up);
        if (k==j)
            return a[j];
        else if (k>j)
            low=j+1;
        else
            up=j-1;
    }
}

int main()
{
    char a[MAX], i;
    printf("Enter elements: ");
    for (i=1; i<11; i++)
        scanf("%c ", &a[i]);
    printf("%c ", KthSmallest(a, 10, 7));
    return 0;
}
