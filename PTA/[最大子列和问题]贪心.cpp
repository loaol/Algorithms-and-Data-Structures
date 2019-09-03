#include<stdio.h>

int main()
{
	int n,a;
	int t=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		t=t+a;
		if (t<0)
			t=0;
		if (t>ans)
			ans=t;
	}
	printf("%d\n",ans);
	return 0;
}
