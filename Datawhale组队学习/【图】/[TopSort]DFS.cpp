#define OK 1
#define ERROR 0
#define MVNum 100
 
typedef int Status;
typedef char VerTexType;
typedef char OtherInfo;
 
typedef struct StackNode{
	int data;
	StackNode *next;
}StackNode,*StackList;
 
typedef struct ArcNode{
	int adjvex;
	ArcNode *nextarc;
	OtherInfo info;
}ArcNode;
 
typedef struct VNode{
	VerTexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];
 
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int indegree[MVNum] = {0};

StackList Push(StackList S,int e)
{
	StackList p;
	p = (StackNode *)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return S;
}

StackList Pop(StackList S, int *e)
{
	StackList p;
	p = S;
	if (!p)
		return ERROR;
	*e = p->data;
	S = S->next;
	free(p);
	return S;
}

int LocateVex(ALGraph *G, VerTexType v)
{
	int i;
	for (i = 0; i < (G->vexnum); i++)
	{
		if (v == G->vertices[i].data)
			return i;
	}
}
 
void CreateUDG(ALGraph *G)
{
	int i, j, k;
	VerTexType v1, v2;
	ArcNode *p1;
	printf("输入总节点数和总边数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	fflush(stdin);
	printf("输入各个节点的值：");
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		fflush(stdin);
		printf("输入一条边的两个节点：");
		scanf("%c %c", &v1, &v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p1 = (ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;
		indegree[j]++;
	}
}

Status TopologicalSort(ALGraph G, int *topo)
{
	int i, m, k;
	StackList S;
	ArcNode *p;
	S = NULL;
	for (i = 0; i < G.vexnum; i++)
	{
		if (!indegree[i])
			S=Push(S, i);
	}
	m = 0;
	while (S)
	{
		S=Pop(S, &i);
		topo[m] = i;
		++m;
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			--indegree[k];
			if (indegree[k] == 0)
				S=Push(S, k);
			p = p->nextarc;
		}
	}
	topo[m] = -1;
	if (m < G.vexnum)
		return ERROR;
	else
		return OK;
}

int main()
{
	ALGraph G;
	int i;
	int topo[99] = {0};
	CreateUDG(&G);
	if (TopologicalSort(G, topo))
	{
		for (i = 0; topo[i] != -1; i++)
		{
			printf("%c ", G.vertices[topo[i]].data);
		}
	}
	else
		printf("错误");
	printf("\n");
	return 0;
}

