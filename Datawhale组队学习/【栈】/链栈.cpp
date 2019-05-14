#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkStack;

//≈–∂œø’’ª 
int StackEmpty(LinkStack *top)
{
	return (top?0:1);
}

//»°’ª∂•‘™Àÿ 
int StackTop(LinkStack *top)
{
	if (StackEmpty(top))
	{
		printf("Stack Empty\n");
		return NULL;
	}
	else
		return top->data;	
}

//»Î’ª 
LinkStack *Push(LinkStack *top,int x)
{
	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=x;
	p->next=top;
	top=p;
	return top; 
}

//≥ˆ’ª
LinkStack *Pop(LinkStack *top)
{
	if (StackEmpty(top))
	{
		printf("Stack Empty\n");
		return NULL;
	}
	top=top->next;
	return top;
	
}

// ‰≥ˆ’ª
void StackPrint(LinkStack *top)
{
	LinkStack *p;
	p=top;
	if (StackEmpty(top))
		printf("Empty Stack!");
	else
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->next;
		}
	putchar('\n');
}

int main()
{
	int a[6]={1,13,53,65,88,90};
	LinkStack *top;
	top=NULL;//≥ı ºªØ’ª 
	
	for (int i=0;i<6;i++)
		top=Push(top,a[i]);
	StackPrint(top);
	
	top=Push(top,100);
	printf("Push '%d' into the Stack\n",100);
	StackPrint(top);
	
	printf("Pop the top(%d) of Stack\n",StackTop(top));
	top=Pop(top);
	StackPrint(top);
	return 0;
}

