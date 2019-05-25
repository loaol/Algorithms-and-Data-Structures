#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n)
{
	int dp[50];
	dp[1]=1;dp[2]=2;
	for (int i=3;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",climbStairs(n));
	return 0;
}
