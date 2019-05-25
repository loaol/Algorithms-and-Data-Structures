#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 10000

int main()
{
  int data[MAXDATA]; /*数据序列*/
  int lgs[MAXDATA];  /*最长子序列长度*/
  int n,temp,k; /*n 序列长度 temp 子序列长度中间变量 */
  
  scanf("%d",&n);
  if(n>10000)
     return 0;      
  for(int i=0;i<n;i++)
    scanf("%d",&data[i]);
    
  for(int i=0;i<MAXDATA;i++)
    lgs[i]=1;  /*给每一个序列点作为右端时的最大序列长度为1*/
  for(int i=1;i<n;i++)
  {
    temp=1;
    for(int j=0;j<i;j++) /*与其前面的每一个进行比较*/
      if(data[i]>data[j]) /*如果数据比前面的某一个的值大*/
        if(lgs[i]+lgs[j]>temp) /*找出该点的最大子序列长度*/
          temp=lgs[i]+lgs[j];
    lgs[i]=temp;
  }
  temp=lgs[0];
  for(int i=1;i<n;i++)
    if(lgs[i]>temp)
      temp=lgs[i];
      
  printf("%d",temp);
  return 0; 
}
