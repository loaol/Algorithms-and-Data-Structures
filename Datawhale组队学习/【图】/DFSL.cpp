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
}lkgraph;

int Nodes[5][3]={{1,2,2},{2,3,9},{0,3,11},{1,4,5},{4,2,7}};
int visid[6]={};

void CreatGraph(lkgraph *ga)
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

void DFSL(lkgraph *ga,int n)
{
	pointer p;
	
	printf("%d\n",ga->AdjList[n].data);
	visid[n]=1;
	for (p=ga->AdjList[n].first;p!=NULL;p=p->next)
		if (!visid[p->vertex])
			DFSL(ga,p->vertex);
}

void DFS(lkgraph *ga)
{
	//初始化 
	for (int i=0;i<ga->n;i++)
		visid[i]=0;
	
	for (int i=0;i<ga->n;i++)
		if  (!visid[i])
			DFSL(ga,i);
}

int numofG(lkgraph *ga)
{
	int k=0;
	for (int i=0;i<ga->n;i++)
		visid[i]=0;
	for (int i=0;i<ga->n;i++)
		if (visid[i]==0)
		{
			k++;
			//printf("\n");
			DFSL(ga,i);
		}
	return k;
}

int main()
{
	lkgraph ga[6];
	CreatGraph(ga);
	DFS(ga);
	return 0;
}
