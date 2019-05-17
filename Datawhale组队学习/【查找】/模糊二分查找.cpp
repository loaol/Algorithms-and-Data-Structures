#include<stdio.h>
#include<stdlib.h>

//找到返回位置，没找到返回0 
int BinSelect(int *a,int k,int n) 
{
	int l=0,h=n-1,m,t=0;
	while(l<h)
	{
		m=(l+h)/2;
		if (a[m]==k)
			return m+1;
		if (a[m]>k)
			h=m;
		else
			l=m+1;
	}
	m=(l+h)/2;//l==h时需要使m=(l+h)/2 
	return m+1;
}

int main()
{
	int n=10;
	int a[] = {11,21,31,41,51,61,71,81,91,101};
	printf("%d\n",BinSelect(a,47,n));
	return 0;
}
