#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void print(int *str,int str_size)
{
	for(int i = 0; i < str_size; i++)
    {
        printf("%d ",str[i]);
    }
    printf("\n");
}

void perm(int *str, int index, int str_size)
{
    if(index == str_size)
        print(str,str_size);
    else
    {
        for(int j = index;j < str_size; j++)
        {
            swap(&str[j],&str[index]);
            perm(str,index+1,str_size);
            swap(&str[j],&str[index]);
        }
    }
}

int main()
{
    int a[4] = {1,2,3,4};
    perm(a,0,4);
    return 0;
}
