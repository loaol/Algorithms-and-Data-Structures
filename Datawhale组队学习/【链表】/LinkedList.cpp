#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList CreateList_L(LinkList &head,int n)
{
    head=(LinkList) calloc(1,sizeof(LNode));  //先建立一个带头结点的单链表
    head->next=NULL; //初始化 
    while(n--)
    {
        LinkList p=(LinkList) calloc(1,sizeof(LNode)); //动态开辟新的结点
        scanf("%d",&p->data);   //输入结点的值
        p->next=head->next;
        head->next=p; //插入到表头
    }
    return head;
}

//在第i个位置后插入元素e 
int ListInsert_L(LinkList &head,int i,int e)
{
    LinkList p=head;
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
    LinkList q=(LinkList) calloc(1,sizeof(LNode)); //动态开辟新的结点
    q->data=e;     //将e的值赋给新的结点
    q->next=p->next;
    p->next=q; //在i-1位置之后插入新的结点
    return 1;
}

//删除第i个元素 
int ListDelete_L(LinkList &head,int i)
{
    LinkList p,tmp=head;
    p=head->next;
    for (int j=1;j<i;j++)
    	if (p)
    	{
    		p=p->next;
    		tmp=tmp->next;
		}
		else
			break;
	if (!p||i<1)
	{	printf("请输入正确的i值！\n");
		return 0;
	}
    tmp->next=p->next;  //删除第i个位置上的值
    free(p);    //释放i位置上的空间
    return 1;
}

void ListPint_L(LinkList head)
{
	LinkList p;
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
	LinkList head;
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
