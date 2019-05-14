#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define m 5

//循环队列的结构类型定义
typedef int datatype;
typedef struct
{
    datatype sequ[m];
    int  rear, quelen;
}qu;

//函数声明
qu* creatqueue();
void setnull(qu*);
void enqueue(qu*, datatype);
datatype *dequeue(qu*);
void print(qu*);

//主函数
void main()
{
    qu *sq= creatqueue();

    datatype x, *p;
    int key;

    setnull(sq);
    do
    {
        printf("1.Enter Queue   2.Delete Queue   3.clc display   4.print queue   -1.Quit:");
        scanf_s("%d", &key);
        switch (key)
        {
        case 1:  printf("Enter the Data:"); scanf_s("%d", &x);
            enqueue(sq, x);  break;
        case 2:  p = dequeue(sq);
            if (p != NULL) printf("%d\n", *p);
            break;
        case 3:system("cls"); break;
        case 4:print(sq); break;
        case -1: exit(0);
        }
    } while (1);
}

//建立队
qu* creatqueue()
{
    qu *sq;
    sq=(qu*)malloc(sizeof(qu));
    return sq;  
}
//置空队
void setnull(qu *sq)
{
    sq->rear = m - 1;
    sq->quelen = 0;
}

//入队
void enqueue(qu*sq, datatype x)
{
    if (sq->quelen == 5)
        printf("Errot! The queue will be overflow! \n");
    else if((sq->rear+1)==m)
    {
        sq->rear = (sq->rear + 1) % m;
        sq->sequ[sq->rear] = x;
        sq->quelen++;
        printf("过5入队成功!\n");
    }
    else
    {
        sq->rear++;
        sq->sequ[sq->rear] = x;
        sq->quelen++;
        printf("入队成功！\n");
    }
}


//出队
datatype *dequeue(qu*sq)
{
    datatype sun=0;
    if (sq->quelen == 0)
    {
        printf("Error! The queue will be under flow!\n");
        return 0;
    }
    else if ((sq->rear + 1) >= sq->quelen)
    {
        sq->quelen--;
        sun = sq->sequ[sq->rear - sq->quelen];
        return(&sun);
    }
    else    //  if(sq->rear < sq->quelen)
    {
        sq->quelen--;
        sun = sq->sequ[sq->rear - sq->quelen + m];
        return(&sun);
    }
}

//打印队列
void print(qu*sq)
{
    if (sq->quelen == 0)
        printf("Error! The queue is Null!\n");
    else if ((sq->rear + 1) >= sq->quelen)
    {
        int i = sq->rear + 1 - sq->quelen;
        for (i; i <= sq->rear; i++)
            printf("%d   ", sq->sequ[i]);
    }
    else
    {
        int t = sq->rear - sq->quelen + m +1;
        int time = 1;
        for (t; time <= (sq->quelen); time++)
        {
            printf("%d   ", sq->sequ[t]);
            t++;
            if (t == m)
            {
                t = 0;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
    printf("\n");
}
