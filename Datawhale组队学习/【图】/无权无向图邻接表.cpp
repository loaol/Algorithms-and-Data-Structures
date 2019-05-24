#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node *pointer;
struct node
{
	int vertex;
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

int Nodes[5][2]={{1,2},{2,3},{0,3},{1,4},{4,2}};

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
		ga->AdjList[Nodes[i][0]].first=p;
		
		p=(pointer)malloc(sizeof(struct node));
		p->vertex=Nodes[i][0];
		p->next=ga->AdjList[Nodes[i][0]].first;
		ga->AdjList[Nodes[i][1]].first=p;
	}
}

int main()
{
	lkgragh ga[6];
	CreatGragh(ga);
	return 0;
}
