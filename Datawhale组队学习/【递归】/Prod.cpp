#include<stdio.h>
#include<stdlib.h>

int prod(int n)
{
	if (n==1)
		return 1;
	return n*prod(n-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",prod(n));
	return 0;
}
