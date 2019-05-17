#include<stdio.h>
#include<stdlib.h>

void SelectSort(int *a,int n)
{
	for (int i=0;i<n-1;i++)
	{
		int k=i;
		for (int j=i+1;j<n;j++)
			if (a[j]<a[k])
				k=j;
		if (k!=i)
		{
			int t=a[i];
			a[i]=a[k];
			a[k]=t;
		}	
	}
}

void PrintArray(int *a,int n)
{
	for (int i=0;i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n=10;
	int a[] = {10,6,7,1,3,9,4,2,5,8};
	SelectSort(a,n);
	PrintArray(a,n);
	return 0;
} 
