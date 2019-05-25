#include<stdio.h>
#include<stdlib.h>

int main()
{
	int grid[100][101],l[100][100],m,n;
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&grid[i][j]);
	
	int *dp=(int *)calloc(n+1,sizeof(int));
	
	for (int i=0;i<=m;i++)
		for (int j=0;j<=n;j++)
			l[i+j+1][j]=grid[i][j]; //按步数排列grid 
	
	for (int j=0;j<n;j++)
		dp[j]=l[m+n-1][j];
	for (int i=m+n-2;i>=1;i--)
	{	
/*		for (int j=1;j<=n;j++)
			printf("%d ",dp[j]);
		printf("\n");	*/
		for (int j=0;j<n;j++)
			if (l[i][j]!=0)
				if (l[i+1][j]!=0 && l[i+1][j+1]!=0)
					dp[j]=((l[i][j]+dp[j])<(l[i][j]+dp[j+1]))?(l[i][j]+dp[j]):(l[i][j]+dp[j+1]);
				else if (l[i+1][j+1]==0)
					dp[j]=l[i][j]+dp[j];
				else
					dp[j]=l[i][j]+dp[j+1];
	}
				
	
	printf("%d\n",dp[0]);
/*	for (int i=1;i<=m+n-1;i++)
	{
		for (int j=0;j<n;j++)
			printf("%d ",l[i][j]);
		printf("\n");
	}	
	return 0;	*/
}
