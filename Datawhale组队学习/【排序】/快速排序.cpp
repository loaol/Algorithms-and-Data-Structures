#include<stdio.h>
#include<stdlib.h>

void quickSort(int* nums,int first,int end)
{
    int temp,l,r;
    if(first>=end)
		return;
    temp=nums[first];
    l=first;r=end;
    while(l<r)
	{
        while(l<r && nums[r]>=temp)
			r--;
        if(l<r)
			nums[l]=nums[r];
        while(l<r && nums[l]<=temp)
			l++;
        if(l<r)
			nums[r]=nums[l];
    }
    nums[l]=temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
} //¿ìÅÅ

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
	quickSort(a,0,n-1);
	PrintArray(a,n);
	return 0;
} 
