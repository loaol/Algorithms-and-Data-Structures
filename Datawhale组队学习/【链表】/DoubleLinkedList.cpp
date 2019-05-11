#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode *next;
	struct DNode *prior;
}DNode,*DLinkList;

int InitDList(DLinkList &head)
{
	head=(DLinkList)calloc(1,sizeof(DLinkList));
	if (head==NULL)
		return 0;
	head->next=head->prior=NULL;
	return 1;
 }
 
 DLinkList CreateList_L(DLinkList &head,int n)
{
    while(n--)
    {
        DLinkList p=(DLinkList) calloc(1,sizeof(DNode)); //动态开辟新的结点
        scanf("%d",&p->data);   //输入结点的值
        p->next=head->next;
        head->next=p; //插入到表头
        p->prior=head->prior;
        head->prior=p;
    }
    return head;
}
 
 //在第i个位置后插入元素e 
int ListInsert_L(DLinkList &head,int i,int e)
{
    DLinkList p=head;
    p=p->next;
    for (int j=1;j<i;j++)
    	if (p)
    		p=p->next;
    	else
    		break;
	if (!p||i<1)
	{
		printf("请输入正确的i值！\n");
		return 0;
	}
    DLinkList q=(DLinkList) calloc(1,sizeof(DNode)); //动态开辟新的结点
    q->data=e;     //将e的值赋给新的结点
    q->next=p->next;
    p->next=q; //在i-1位置之后插入新的结点
    q->prior=p->prior;
    p->prior=q;
    return 1;
}

//删除第i个元素 
int ListDelete_L(DLinkList &head,int i)
{
	int j;
	DLinkList t1,t2;
	j=1;
	t1=head->next;
	t2=head;
	while(j<i&&t1!=head)
	{
		j++;
		t1=t1->next;
		t2=t2->next;
	}
	if(j>i)
		return 0;
	t2->next=t1->next;
	t2->prior=t1->prior;
	free(t1);
	return 1;
}

void ListPint_L(DLinkList &head)
{
	DLinkList p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int main()
{
	int i,n;
	char cmd,e;
	DLinkList head;
	InitDList(head);
	scanf("%d",&n);
	CreateList_L(head,n);
	ListPint_L(head);
	putchar('\n');
	ListInsert_L(head,2,1);
	ListPint_L(head);
	putchar('\n');
	ListDelete_L(head,2);
	ListPint_L(head);
	return 0;
}
