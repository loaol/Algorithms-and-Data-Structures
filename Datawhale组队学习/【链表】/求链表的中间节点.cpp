#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;

typedef struct SListNode
{
    DataType data;
    struct SListNode* next;
}SListNode;

SListNode* BuyNode(DataType x)
{
    SListNode* next = (SListNode*)malloc(sizeof(SListNode));
    next->data = x;
    next->next = NULL;
    return next;
}

void PushBack(SListNode* & ppHead, DataType x)
{
    if (ppHead == NULL)
    {
        ppHead = BuyNode(x);
    }
    else
    {
        SListNode* tail = ppHead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = BuyNode(x);
    }
}
//查找单链表的中间节点，要求只能遍历一次
SListNode* FindMiddle(SListNode* ppHead)
{
    SListNode* slow = ppHead;
    SListNode* fast = ppHead;
    while (fast)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        else
        {
            return slow;
        }
    }
    return slow;
}
void PrintSNodeList(SListNode* ppHead)
{
    while (ppHead)
    {
        printf("%d->", ppHead->data);
        ppHead = ppHead->next;
    }
    printf("\n");
}

void Test3()
{
    SListNode* List = NULL;
    PushBack(List, 1);
    PushBack(List, 2);
    PushBack(List, 3);
    PushBack(List, 4);
    PushBack(List, 5);
    PrintSNodeList(List);
    SListNode *ret=FindMiddle(List);
    printf("%d ", ret->data);
}

int main()
{
    Test3();
    system("pause");
    return 0;
}
