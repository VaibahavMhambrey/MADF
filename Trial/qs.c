#include<stdio.h>

void sw(int a[], int x, int b)
{
int t=a[x];
a[x]=a[b], a[b]=t;
}

int part(int a[], int l, int r)
{

int piv=a[r], i=l-1, j;
for(j=l;j<r;j++)
{

if(a[j]<piv)
{

i++;
sw(a, i, j);
}

}
sw(a, i+1, r);
return i+1;
}

void qs(int a[], int l, int r)
{

if(l<r)
{

int pi=part(a, l , r);
// calling qs on both sides
qs(a, l, pi-1);
qs(a, pi+1, r);

}
	
}

int main()
{
	int size;
	printf("enter the size of the array: ");
	scanf("%d", &size);
	int a[size];
	for(int i=0;i<size;i++)
	scanf("%d", &a[i]);
	qs(a, 0, size-1);
    	for (int i = 0; i < size; i++)
       	printf("%d, ", a[i]);
    	printf("\n");
}
