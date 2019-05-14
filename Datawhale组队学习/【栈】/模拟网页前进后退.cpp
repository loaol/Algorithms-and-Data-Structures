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

//前进 
void *GoAhead(SeqStack *ahead,SeqStack *back)
{
	if (back->top==0) //到达最开始浏览的页面1 
	{
		printf("Can't go ahead\n");
		return NULL; 
	}
	else
	{
		ahead->top++;
		ahead->stack[ahead->top]=back->stack[back->top];
		back->top--;
	}
}

//后退 
void *GoBack(SeqStack *ahead,SeqStack *back)
{
	if (ahead->top==-1) //到达最后浏览的页面6 
	{
		printf("Can't go ahead\n");
		return NULL; 
	}
	else
	{
		back->top++;
		back->stack[back->top]=ahead->stack[ahead->top];
		ahead->top--;
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
	int a[6]={1,2,3,4,5,6};
	SeqStack *ahead,*back;
	
	ahead=InitStack();
	back=InitStack();
	
	//当前页面为页面3 
	//浏览过页面1，2，3 
	for (int i=0;i<3;i++)
		Push(back,a[i]);
	//已后退的页面4、5、6 
	for (int i=5;i>=3;i--)
		Push(ahead,a[i]);
	StackPrint(back);
	StackPrint(ahead);
	printf("当前页面：%d\n",back->stack[back->top]);
	
	GoAhead(ahead,back);	
	StackPrint(back);
	StackPrint(ahead);
	printf("当前页面：%d\n",back->stack[back->top]);
	GoBack(ahead,back);
	GoBack(ahead,back);
	StackPrint(back);
	StackPrint(ahead);
	printf("当前页面：%d\n",back->stack[back->top]);	
	return 0;
}
