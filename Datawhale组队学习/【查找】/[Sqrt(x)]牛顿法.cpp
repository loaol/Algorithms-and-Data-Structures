#include<stdio.h>
#include<stdlib.h>

int mysqrt(int a)
{
	double x,y;
	x=1.0;
    while(x*x-a<-0.00001||x*x-a>0.00001)
	{
 		y=(x+a/x)/2.0;
 		x=y;
	}
	return x;
}

int main()
{
	int a=99;
	printf("%d\n",mysqrt(a)+1);
	return 0;
}
