#include <stdio.h>
#include <math.h>
#define MAX 11
int a[MAX] = {81, 43, 61, 21, -8, 96, 11, 77, -18, 12, 17};

void mergesort(int low, int high);
void merge(int low, int mid, int high);
int binarysearch(int low, int high, int x);

int main()
{
    int i, x, low, high, mid;
    int b[MAX];
    int pos;

 printf("enter element to be searched\n");
 scanf("%d",&x);
 mergesort(0,10);
 for(i=0;i<=10;i++)
    printf("%d ",a[i]);
 pos=binarysearch(0,10,x);
 printf("element %d found at position of %d",x,pos+1);

}

void mergesort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int b[MAX];
    int k;
    int h = low, i = low, j = mid + 1;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] >= a[j])
        {
            b[i] = a[j];
            j = j + 1;
        }
        else
        {
            b[i] = a[h];
            h = h + 1;
        }
        i = i + 1;
    }
    if (h > mid)
    {
        for (k = j; k<=high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {

            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

int binarysearch(int low, int high, int x)
{
    int mid;
    if (low == high)
    {
        if (a[low] == x)
            return low;
        else
            return -1;
    }

    else
    {
        mid = (low + high)/2;
        if (a[mid] == x)
            return mid;
        else if (x > a[mid])
            return binarysearch(mid + 1, high, x);
        else
            return binarysearch(low, mid - 1, x);
    }
}