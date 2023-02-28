#include<stdio.h>

int small_k(int *a,int n,int k);
int partition(int *a,int low,int high);
void display(int a[],int n);

int main(){
	int a[100];
	int i,n,k;
	printf("give number of elements\n");
	scanf("%d",&n);
    printf("enter the elements\n");
	for(i=0;i<n;i++)
    {	
		scanf("%d",&a[i]);
	}
	printf("give the element to search\n");
	scanf("%d",&k);
	k=small_k(a,n,k-1);
	printf("\n%dth smallest element is %d",k+1,a[k]);
}

int small_k(int a[],int n,int k)
{
	int j,low=0,up=n;
    a[n]=1000;
	do{
		
		j=partition(a,low,up);
        printf("j=%d\n",j);
        display(a,n);
		if(k==j){
			return j;
		}
		else if(k<j){
			up=j;
			
		}
		else 
			low=j+1;
	}
	while(1);
}

int partition(int a[],int low,int high)
{
    int pivot=a[low],i=low+1,j=high,temp;
    do{
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void display(int a[],int n)
{
    int i;
    printf("\nPrinting the array\n");
	for(i=0;i<n;i++)
    {	
		printf("%d ",a[i]);
	}
}