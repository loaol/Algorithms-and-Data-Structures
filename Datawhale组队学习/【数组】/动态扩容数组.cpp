#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,n=0;
	int *array;
	array=(int*)calloc(5,sizeof(int)); //申请5个长度为int的内存空间 
	if (!array) //判断是否申请成功 
    {
        printf("申请失败！");
		return 0; 
    }
	while (1)
	{	
		//读入 
		scanf("%d",&t);
		if (t==0) //遇到0则结束读入数组 
			break;
		*(array+n)=t;
		n++;
    	if (n%5==0) //如果满了，就申请2倍原长的数组 
    		array=(int*)realloc(array,2*n*sizeof(int));
	}
	printf("----输出----\n");
	for(int i=0;i<n;i++)
		printf("%d ",array[i]);
	putchar('\n');
	free(array); //释放内存 
	return 0;	
}
