#include<stdio.h>
#include<stdlib.h>
#define N 5

int Mat[N][N]={};
int Nodes[5][2]={{1,2},{2,3},{0,3},{1,4},{4,2}};

void PrintMat()
{
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N-1;j++)
			printf("%d ",Mat[i][j]);
		printf("%d\n",Mat[i][N-1]);
	}
}

void AdjMat()
{
	for (int i=0;i<sizeof(Nodes)/sizeof(Nodes[0]);i++)
		Mat[Nodes[i][0]][Nodes[i][1]]=1;
}

int main()
{
	AdjMat();
	PrintMat();
	return 0;
}
