#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int m, int B[], int n)
{
    int i,j,k;
    for(int i=m-1,j=n-1,k=n+m-1;k>=0;--k) //遍历 
    {
    	//排序结果放入数组A; 
        if( i >= 0 &&(j < 0 || A[i] >= B[j])) //比较A[i]和B[j]的大小且A、B不为空 
        	A[k] = A[i--];
        else            
            A[k] = B[j--];
    }
}

int main()
{
	int A[20]={1,3,5,7};
	int B[4]={2,4,6,8};
	int m=4,n=4;
	merge(A,m,B,n); //合并排序 
	for (int i=0;i<m+n;i++)
		printf("%d ",A[i]);
	return 0;
}
