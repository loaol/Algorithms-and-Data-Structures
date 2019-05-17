#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int *a,int n)
{
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			if (a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
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
	BubbleSort(a,n);
	PrintArray(a,n);
	return 0;
} 
