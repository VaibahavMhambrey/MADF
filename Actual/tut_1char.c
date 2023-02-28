#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX 11
char a[MAX] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a'};

int binarysearch(int low, int high, char x);
void mergesort(int low, int high);
void merge(int low, int mid, int high);

int main()
{
	int i, low, high, mid;
	int b[MAX];
	int pos;
	char ch;

    mergesort(0, 10);
	printf("Sorted Character array: \n");
	for (i = 0; i <= 10; i++)
		printf("%c ", a[i]);

	mergesort(0, 10);
	printf("\nEnter element to be searched: \n");
	scanf("%c", &ch);
	pos=binarysearch(0,10,ch);
		printf("Element %c found at position of %d", ch, pos + 1);
}

void mergesort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(mid + 1, high);
		mergesort(low, mid);
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
		for (k = j; k <= high; k++)
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

int binarysearch(int low, int high, char x)
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
		mid = (low + high) / 2;
		if (a[mid] == x)
			return mid;
		else if (x > a[mid])
			return binarysearch(mid + 1, high, x);
		else
			return binarysearch(low, mid - 1, x);
	}
}