#include<stdio.h>
#include<stdlib.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
#define OVERFLOW -2
typedef int Status ;
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
//队列结构定义
typedef struct LQueue
{
	QueuePtr front;            //队头
	QueuePtr rear;             //队尾
}LQueue;
 
Status Visit(QElemType e);
 
/*②队列的基本操作接口定义*/
//1-初始化：构造一个空队列Q
Status InitLQueue(LQueue &Q);
 
//2-销毁：销毁一个队列Q
Status DestroyLQueue(LQueue &Q);
 
//3-清空：清空一个队列Q
Status ClearLQueue(LQueue &Q);
 
//4-是否为空队列：判断队列是否为Q空
Status IsLQueueEmpty(LQueue Q);
 
//5-队列长度：返回队列元素Q的个数
int LQueueLength(LQueue Q);
 
//6-获取队头元素：用e返回Q的队头元素
Status GetFrontElem(LQueue Q,QElemType &e);
 
//7-入队：队列Q已经存在，插入元素e为队列的队尾元素
Status EnLQueue(LQueue &Q,QElemType e);
 
//8-出队：队列Q非空，删除队头元素，用e返回
Status DeLQueue(LQueue &Q,QElemType &e);
 
//9-遍历：队列Q存在且非空，依次对Q的每个元素调用Visit()，
//进行遍历。一旦Visit失败，则操作失败
Status LQueueTraverse(LQueue Q,Status (*Visit)(QElemType e));
 
// LQueueTraverse操作中 访问队列中的一个元素e所使用的函数
Status Visit(QElemType e)
{
	printf("%d\n",e);
	return OK;
}
 
/*③队列基本操作实现*/
//1-初始化：构造一个空队列Q
Status InitLQueue(LQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit (OVERFLOW); 
	Q.front->next=NULL;
	return OK;
}
 
//2-销毁：销毁一个队列Q
Status DestroyLQueue(LQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}
 
//3-清空：清空一个队列Q
Status ClearLQueue(LQueue &Q)
{
	QueuePtr p,s;
	Q.rear=Q.front;
	p=Q.front->next;
	s=p;
	while(p)
	{
		s=p->next;
		free(p);
		p=s;
	}
	return OK;
}
 
//4-是否为空队列：判断队列是否为Q空
Status IsLQueueEmpty(LQueue Q)
{
	if(Q.front==Q.rear) 
		return TRUE;
	else 
		return FALSE;
}
 
//5-队列长度：返回队列元素Q的个数
int LQueueLength(LQueue Q)
{
	QueuePtr p;
	int length=0;
	if(Q.front==Q.rear) 
		return 0;
	else
	{
		p=Q.front->next;
		while(p)
		{
		    length++;
		p=p->next;
		}
	}
	return length;
}
 
//6-获取队头元素：用e返回Q的队头元素
Status GetFrontElem(LQueue Q,QElemType &e)
{
	if(Q.front==Q.rear) 
		return ERROR;
	e=Q.front->next->data;
	return OK;
}
 
//7-入队：队列Q已经存在，插入元素e为队列的队尾元素
Status EnLQueue(LQueue &Q,QElemType e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)  exit (OVERFLOW);
	p->data =e;
	p->next =NULL;
	Q.rear->next=p;
	Q.rear =p;
	return OK;
}
 
//8-出队：队列Q非空，删除队头元素，用e返回
Status DeLQueue(LQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
 
//9-遍历：队列Q存在且非空，依次对Q的每个元素调用Visit()，
//进行遍历。一旦Visit失败，则操作失败
Status LQueueTraverse(LQueue Q,Status (*Visit)(QElemType e))
{
    QueuePtr p;
	if(Q.front==Q.rear) 
		return ERROR;
	else
	{
		p=Q.front->next;
		while(p)
		{
		    Visit(p->data);
		p=p->next;
		}
	}
	return OK;
}
 
 
void main()
{
	LQueue Q;
	QElemType e;
    int i,a;
    InitLQueue(Q);//初始化
    //入队列10个随机整数
	printf("输入10个整数在队列中：");
    for(i=0;i<10;i++)
	{
		scanf("%d",&e);
		EnLQueue(Q,e);
	}
    //遍历
	printf("遍历队列\n");
	LQueueTraverse(Q, Visit);
  //出队列5个数
	for(i=0;i<5;i++)
	{
		DeLQueue(Q,e);
	}
	//再次遍历
	printf("再次遍历队列\n");
	LQueueTraverse(Q,Visit);
    a=LQueueLength(Q);
	printf("队列长度为:%d\n",a);
    DestroyLQueue(Q);
	printf("销毁队列成功！\n");
    system("pause");
}
