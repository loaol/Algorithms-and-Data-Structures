#include "stdio.h"
#include<stdlib.h>
#define N 6
#define	MAX	9999

void Path(int *p,int v,int i)
{
	int que[N];
	int t=v;
	que[t++]=i;
	int tmp=p[i];
	while(tmp!=v)
	  {
		que[t]=tmp;
		t++;
		tmp=p[tmp];
	   }
	que[t]=v;
	for(int k=t;k>=1;--k)
		if(k!=1)
			printf("%d-->",que[k]);
		else
		  {  printf("%d",que[k]);
	         printf("\n");
	      }
}



int  main()
{
	int  cost[N][N]={     
		                  {MAX,MAX,MAX,MAX,MAX,MAX},
		                  {MAX,MAX,10,MAX,30,100},
		                  {MAX,MAX,MAX,50,MAX,MAX},
		                  {MAX,MAX,MAX,MAX,MAX,10},
		                  {MAX,MAX,MAX,20,MAX,60},
		                  {MAX,MAX,MAX,MAX,MAX,MAX}
	              };
	int S[N];
	int dist[N];
	int p[N];
	int i,j,u,min;
for(i=1;i<N;i++)
	  {
       S[i]=0;
	   dist[i]=cost[1][i];
	   if(dist[i]==MAX)
		  p[i]=0;
	   else	  p[i]=1;
	  }
	S[1]=1;
    for(i=2;i<N;i++)
	 {  
	    min=MAX;
        for(j=1;j<N;j++)  
	      {
	        if(!S[j]&&dist[j]<min)
		      {
                u=j;
			     min=dist[j];
		       }
	       }
		 S[u]=1;
        for(j=1;j<N;j++)
	       if(!S[j]&&min+cost[u][j]<dist[j])
		     {
			     dist[j]= min+cost[u][j]; 
			     p[j]=u;  
		      }

	   }
    for(i=2;i<N;i++)
	   {
		   printf("the shortest line 1--->%d:%d",i,dist[i]);
		   printf("¶¥µã±éÀú:");
           Path(p,1,i);
		   
	    } 
	
    system("pause");
}

