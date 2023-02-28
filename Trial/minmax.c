#include<stdio.h>

void minmax(int a[], int l, int r, int *min, int *max)
{
	if(l==r)
	{
		*min=*max=a[l];
	}
	else if(r==l+1)
	{
		if(a[l]<a[r])
			*min=a[l], *max=a[r];
		else
			*min=a[r], *max=a[l];
	}
	else
	{
		int lmin, lmax, rmin, rmax;
		int mid=(l+r)/2;
		minmax(a, l, mid-1, &lmin, &lmax);
		printf("lmin: %d, lmax: %d\n", lmin, lmax);
		minmax(a, mid+1, r, &rmin, &rmax);
		printf("rmin: %d, rmax: %d\n", rmin, rmax);
		*min=(lmin<rmin)?lmin:rmin;
		*max=(lmax>rmax)?lmax:rmax;
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
	int min, max;
	minmax(a, 0, size-1, &min, &max);
	printf("min: %d max: %d\n",min, max); 
}
