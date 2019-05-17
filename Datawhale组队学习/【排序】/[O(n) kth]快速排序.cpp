#include<stdio.h>
#include<stdlib.h>

int quickSort(int k,int* nums,int first,int end)
{
    int temp,l,r;
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
    if (l>k-1)
    	return quickSort(k,nums,first,l-1);
    else if (l<k-1)
		return quickSort(k,nums,l+1,end);
	else
		return nums[l];
} //¿ìÅÅ

void PrintArray(int *a,int n)
{
	for (int i=0;i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n=10,k=3,kth;
	int a[] = {10,6,7,1,3,9,4,2,5,8};
	kth=quickSort(k,a,0,n-1);
	printf("%d\n",kth);
	PrintArray(a,n);
	return 0;
}
