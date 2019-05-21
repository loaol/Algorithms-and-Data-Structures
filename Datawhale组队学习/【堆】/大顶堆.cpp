#include<stdio.h>
#include<stdlib.h>
  
void adjustMaxHeap(int a[], int len, int parentNodeIndex)
{
	if (len <= 1) 
		return;
	int targetIndex = -1;
	int leftChildIndex = 2 * parentNodeIndex + 1;
	int rightChildIndex = 2 * parentNodeIndex + 2;
	
	if (leftChildIndex >= len)
		return;
	if (rightChildIndex >= len) 
		targetIndex = leftChildIndex;
	else
		targetIndex = a[leftChildIndex] > a[rightChildIndex] ? leftChildIndex : rightChildIndex;
	if (a[targetIndex] > a[parentNodeIndex])
	{
		int temp = a[targetIndex];
		a[targetIndex] = a[parentNodeIndex];
		a[parentNodeIndex] = temp;
		adjustMaxHeap(a, len, targetIndex);
	}
}

void initHeap(int a[], int len) 
{
	for (int i = (len - 1) / 2; i >= 0; --i)
		adjustMaxHeap(a, len, i);
}
  
void heapSort(int a[], int len)
{
	if (len <= 1)
		return;
	initHeap(a, len);
	for (int i = len - 1; i > 0; --i)
	{
		if (a[0] > a[i]) 
		{
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
		}
		adjustMaxHeap(a, i - 1, 0);
 	}
}

int main()
{
	// int a[] = {5, 3, 8, 6, 4};
	int a[] = {89,-7,999,-89,7,0,-888,7,-7};
	heapSort(a, sizeof(a) / sizeof(int));
  
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
  		printf("%d ", a[i]);
  	return 0;
}
