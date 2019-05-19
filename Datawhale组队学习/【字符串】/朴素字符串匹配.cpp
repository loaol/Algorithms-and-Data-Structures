#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

using namespace std;
//从pos位置开始，返回子串在主串中的位置
int BF(char *M,char *T,int pos)
{
	int i=pos;
	int j=0;
	int Mlen=strlen(M);//主串的范围[0,Slen)
	int Tlen=strlen(T);//子串的范围[0,Tlen)
 
	if(pos<0 && pos>Mlen)
		return -1;
 
	while(i<Mlen && j<Tlen)
	{
		if(M[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=Tlen)
		return i-Tlen;
	else 
		return -1;
}
int main()
{
	char M[20]="abcdefabcdx";
	char T[20]="abcdx";
	printf("%d",BF(M,T,1));
	return 0;
}
