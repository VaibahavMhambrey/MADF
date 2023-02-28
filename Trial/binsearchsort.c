#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX 11
int a[MAX] = {65,18,40,50,80,90,110,20,25,-75,20};
char c[MAX] = {'J','P','N','S','O','B','V','W','K','E','R'};
void mergesort(int low, int high);
void merge(int low, int mid, int high);
int binarysearch(int low, int high, char x);
void mergesortchar(int low, int high);
void mergechar(int low, int mid, int high);

int main()
{
    int i, low, high, mid;
    int pos;
    char ch;

    mergesort(0,10);
    printf("Sorted integer array: ");
    for(i=0;i<=10;i++)
        printf("%d ",a[i]);
    printf("\n\n");

    mergesortchar(0,10);
    printf("Sorted Character array: ");
    for(i=0;i<=10;i++)
        printf("%c ",c[i]);
    printf("\n\n");

    printf("Enter element to be searched: \n");
    scanf("%c",&ch);
    ch = toupper(ch);
    pos=binarysearch(0,10,ch);
    if(pos == 0){
        printf("Element not found");
    }
    else{
        printf("Element %c found at position of %d",ch,pos+1);
    }
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
        if (a[h] < a[j])
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
    for (k = low; k <= high; k++)//copy
        a[k] = b[k];
}

int binarysearch(int low, int high, char x)
{
    int mid;
    if (low == high)
    {
        if (c[low] == x)
            return low;
        else
            return -1;
    }
    else
    {
        mid = (low + high)/2;
        if (c[mid] == x)
            return mid;
        else if (x > c[mid])
            return binarysearch(mid + 1, high, x);
        else
            return binarysearch(low, mid - 1, x);
    }
}

void mergesortchar(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesortchar(low, mid);
        mergesortchar(mid + 1, high);
        mergechar(low, mid, high);
    }
}

void mergechar(int low, int mid, int high)
{
    char b[MAX];
    int k;
    int h = low, i = low, j = mid + 1;
    while ((h <= mid) && (j <= high))
    {
        if (c[h] >= c[j])
        {
            b[i] = c[j];
            j = j + 1;
        }
        else
        {
            b[i] = c[h];
            h = h + 1;
        }
        i = i + 1;
    }
    if (h > mid)
    {
        for (k = j; k<=high; k++)
        {
            b[i] = c[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {

            b[i] = c[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
        c[k] = b[k];
}