#include<stdio.h>
#include<stdlib.h>

void Adjust_dui(int* a, int s, int k)
{
	int j = 0;
	int tmp = a[s];
	for (j = 2 * s+1; j <= k - 1; j = 2 * j + 1)
	{
		if (j<k - 1 && a[j]>a[j + 1])
			j++;
		if (tmp < a[j]) break;
		a[s] = a[j];
		s = j;
	}
	a[s] = tmp;
}
void create_dui(int* a, int k)
{
	for (int j = k / 2 - 1; j >= 0; j--)
	{
		Adjust_dui(a, j, k);
	}
}
int main()
{
	int a[] = { 4, 2, 1, 5, 6, 9,0, 3, 8, 7 };
	int k = 5;
	int len = sizeof(a) / sizeof(int);
	create_dui(a, k);
 
	for (int i = k; i < len; ++i)
	{
		if (a[i]>a[0])
		{
			a[0] = a[i];
			Adjust_dui(a, 0, k);
		}
	}
	for (int i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
} 
