#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int stack[100];
	int top;
}SeqStack;

//初始化栈（创建空栈） 
SeqStack *InitStack()
{
	SeqStack *S;
	S=(SeqStack *)calloc(1,sizeof(SeqStack));
	if (!S)
	{
		printf("Stack creation failed！");
		return NULL; 
	}
	else
	{
		S->top=-1;
		return S;
	}
}

//判断是否为空栈
int StackEmpty(SeqStack *S)
{
	return (S->top==-1?0:1);
}

//取栈顶元素
int StackTop(SeqStack *S)
{
	if (StackEmpty(S))
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else
		return S->stack[S->top];	
}

//入栈 
SeqStack *Push(SeqStack *S,int x)
{
	if (S->top==100-1)
	{
		printf("Stack Full\n");
		return NULL; 
	}
	else
	{
		S->top++;
		S->stack[S->top]=x;
		return S;
	}
}

//出栈 
int Pop(SeqStack *S)
{
	if (StackEmpty(S))
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else
	{
		S->top--;
		return S->stack[S->top+1];
	}	
}

//输出栈
void StackPrint(SeqStack *S)
{
	int t;
	t=S->top;
	if (S->top==-1)
		printf("Empty Stack!\n");
	else
		while (t!=-1)
		{
			if (t!=0)
				printf("%d->",S->stack[t]);
			else
				printf("%d\n",S->stack[t]);
			t--;
		}
}

int main()
{
	int a[6]={3,5,8,11,35,76};
	SeqStack *p;
	
	p=InitStack();
	
	for (int i=0;i<6;i++)
		Push(p,a[i]);
	StackPrint(p);
	
	Push(p,100);
	printf("Push '%d' into the Stack\n",100);
	StackPrint(p);
	
	printf("Pop the top(%d) of Stack\n",StackTop(p));
	Pop(p);
	StackPrint(p);
	return 0;
}
