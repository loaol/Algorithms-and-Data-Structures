#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
//分组归并
void _Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	int index = begin1;
	int i = begin1, j = begin2;
	//注意:当划分的区间足够小时,begin1==end1,begin2==end2
	while (i <= end1&&j <= end2){
		if (a[i]<=a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//将左边元素填充到tmp中
	while (i <= end1)
		tmp[index++] = a[i++];
	//将右边元素填充的tmp中
	while (j <= end2)
		tmp[index++] = a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	//注意:end2-begin1+1
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}

//归并排序
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	assert(a);
	//mid将数组二分
	int mid = left + ((right - left) >> 1);
	//左边归并排序,使得左子序列有序
	MergeSort(a, left, mid, tmp);
	//右边归并排序,使得右子序列有序
	MergeSort(a, mid + 1, right, tmp);
	//将两个有序子数组合并
	_Merge(a, left, mid, mid + 1, right, tmp);
}

//打印数组
void PrintArray(int *a, int len)
{
	assert(a);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a) / sizeof(int)));
	if (!tmp)
	{
		printf("申请失败"); 
	}
	memset(tmp, -1, sizeof(a) / sizeof(int));
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1, tmp);
	PrintArray(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
} 
