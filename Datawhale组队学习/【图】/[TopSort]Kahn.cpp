#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
inline int init()
{
	int now=0,ju=1;char c;bool flag=false;
	while(1)
	{
		c=getchar();
		if(c=='-')ju=-1;
		else if(c>='0'&&c<='9')
		{
			now=now*10+c-'0';
			flag=true;
		}
		else if(flag)return now*ju;
	}
}
inline long long llinit()
{
	long long now=0,ju=1;char c;bool flag=false;
	while(1)
	{
		c=getchar();
		if(c=='-')ju=-1;
		else if(c>='0'&&c<='9')
		{
			now=now*10+c-'0';
			flag=true;
		}
		else if(flag)return now*ju;
	}
}
struct edge
{
	int from,to,val,pre;
}Edge[100001];
int head[101];
int cnt=0,n,m;
inline void addedge(int from,int to,int val)
{
	cnt++;
	Edge[cnt]=((edge){from,to,val,head[from]});
	head[from]=cnt;
}
int in[101];
void toposort()
{
	queue<int> ans;
	while(!ans.empty())ans.pop();
	int now,x;
	queue<int> q;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
	{
		if(!in[i])q.push(i);
	}
	while(!q.empty())
	{
		now=q.front();q.pop();
		ans.push(now);
		for(int j=head[now];j;j=Edge[j].pre)
		{
			in[Edge[j].to]--;
			if(!in[Edge[j].to])q.push(Edge[j].to);
		}
	}
	while(!ans.empty())
	{
		x=ans.front();ans.pop();
		printf("%d ",x);
	}
}
int main()
{
	int x;
	n=init();
	for(int i=1;i<=n;i++)
	{
		while(scanf("%d",&x),x)addedge(i,x,1),in[x]++;
	}
	toposort();
	return 0;
}
