#include<stdio.h>

int main()
{
	int n,a;
	int t=0,ans=-1;
	int ansf=-1,ansl=-1,f,l;
	scanf("%d",&n);
	scanf("%d",&a);
	ansf=a;
	f=a;
	l=a;
	t=t+a;
	for (int i=2;i<=n;i++)
	{
		if (t<0)
		{
			t=0;
			scanf("%d",&a);
			f=a;
			l=a;
			t=t+a;
			continue;
		}
		if (t>ans)
		{
			ans=t;
			ansf=f;
			ansl=l;
		}
		scanf("%d",&a);
		l=a;
		t=t+a;
	}
	if (t>ans)
		{
			ans=t;
			ansf=f;
			ansl=l;
		}
	if (ans==-1)
	{
		ans=0;
		ansl=a;
	}
	if (ans==0)
		ansl=0;
	printf("%d %d %d\n",ans,ansf,ansl);
	return 0;
}
