#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node *pointer;
struct node
{
	int vertex;
	int data; 
	struct node *next;
}nnode;
typedef struct
{
	int data;
	pointer first;
}head;
typedef struct
{
	head AdjList[N];
	int n,e;
}lkgragh;

int Nodes[5][3]={{1,2,2},{2,3,9},{0,3,11},{1,4,5},{4,2,7}};
void CreatGragh(lkgragh *ga)
{
	//顶点表初始化
	ga->n=5;
	for (int i=0;i<ga->n;i++)
	{
		ga->AdjList[i].first=NULL;
		ga->AdjList[i].data=i; 
	}
	ga->e=sizeof(Nodes)/sizeof(Nodes[0]);
	for (int i=0;i<ga->e;i++)
	{
		pointer p=(pointer)malloc(sizeof(struct node));
		p->vertex=Nodes[i][1];
		p->next=ga->AdjList[Nodes[i][1]].first;
		p->data=Nodes[i][2];
		ga->AdjList[Nodes[i][0]].first=p;
		
		p=(pointer)malloc(sizeof(struct node));
		p->vertex=Nodes[i][0];
		p->next=ga->AdjList[Nodes[i][0]].first;
		p->data=Nodes[i][2];
		ga->AdjList[Nodes[i][1]].first=p;
	}
}

int main()
{
	lkgragh ga[6];
	CreatGragh(ga);
	return 0;
}
