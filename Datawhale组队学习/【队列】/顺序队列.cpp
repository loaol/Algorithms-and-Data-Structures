//顺序队列
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
 
//定义队列的结构体 
typedef struct Squeue{
	int data[Maxsize];
	int front;
	int rear;
}Squeue; 
 
//初始化队列 
void InitQueue(Squeue &qu)
{
	qu.front = qu.rear = 0;
}
 
//判断队列是否为空 
int isQueueEmpty(Squeue qu)
{
	if(qu.front == qu.rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
//元素入队操作 
int inQueue(Squeue &qu,int x)
{
	//若队满则无法入队 
	if((qu.rear + 1) % Maxsize == qu.front)
	{
		return 0;
	}
	qu.rear = (qu.rear + 1) % Maxsize;
	qu.data[qu.rear] = x;
	return 1; 
}
 
//元素出队操作 
int deQueue(Squeue &qu,int &x)
{
	//若队空则无法出队 
	if(qu.front == qu.rear)
	{
		return 0;
	}
	qu.front = (qu.front + 1) % Maxsize;
	x = qu.data[qu.front];
	return 1;
}
 
int main()
{
	Squeue q;
	int i , n , x , a;
	InitQueue(q);
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a);
		inQueue(q,a);
	}
	//当队列非空时，输出队列中所有数据 
	while(!isQueueEmpty(q))
	{
		deQueue(q,x);
		printf("%d ",x);
	}
	return 0;
}
