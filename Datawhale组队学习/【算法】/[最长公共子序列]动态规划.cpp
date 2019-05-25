#include<stdio.h>  
#include<string.h>  
char a[101],b[101];  
char num[102][102];//记录中间结果的数组  
//动态规划采用二维数组来标识中间计算结果，避免重复的计算来提高效率
void LCS(int lena,int lenb){ 
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1]){//注意这里的下标是i-1与j-1  
                num[i][j]=num[i-1][j-1]+1;
            }  
            else{
                num[i][j]=num[i][j-1] > num[i-1][j] ? num[i][j-1] : num[i-1][j];
            }  
        }  
    }  
}
int main(){  
    scanf("%s%s",&a,&b);//输入字符串
    int lena = strlen(a);//获取字符串长度 
    int lenb = strlen(b);
    memset(num,0,sizeof(num));//数组赋初值  
    LCS(lena,lenb);
    printf("%d",num[lena][lenb]); 
    return 0;
}
