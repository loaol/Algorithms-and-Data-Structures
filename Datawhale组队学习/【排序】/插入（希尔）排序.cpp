#include <stdio.h>
#include <stdlib.h>

void ShellSort(int a[], int length)
{
	int increment;
	int i,j;
	int temp;
	for(increment = length/2; increment > 0; increment /= 2) //用来控制步长,最后递减到1
	{
		// i从第step开始排列，应为插入排序的第一个元素
		// 可以先不动，从第二个开始排序
		for(i = increment; i < length; i++)
		{
			temp = a[i];
			for(j = i - increment; j >= 0 && temp < a[j]; j -= increment)
			{
				a[j + increment] = a[j];
			}
			a[j + increment] = temp; //将第一个位置填上
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
	ShellSort(a,n);
	PrintArray(a,n);
	return 0;
} 
