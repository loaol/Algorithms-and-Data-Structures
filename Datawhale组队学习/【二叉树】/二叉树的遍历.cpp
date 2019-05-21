#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

typedef struct biTree{
	int data;
	struct biTree * lchild, * rchild;
}biTree, *bipts;// 基本的二叉树结点

bipts createBiTree(bipts bt){
	// 这段代码参照我之前的博文”【C语言】输入带空格的数字字符串“
    char read[10001];
    int input;
    int i = 0;
    int j = 0;// initialize
    int k = 0;
    int convert[10001];// char -> int
    while(1){
        input = getchar();
        read[j] = input;
        j++;
        if(input == ' ' || input == '\n' || input == EOF){
            read[j-1] = '\0';
            convert[i] = atoi(read);
            i++;
            memset(read, 0, sizeof(read));
            j = 0;
            if(input == '\n' || input == EOF){
                convert[i] = -1;
                convert[i+1] = '\0';
                break;
            }
        }
    }
	int front, rear;// 分别记住前面的数和后面的数
	int ch;
	int node = 0;// 记住是第几个数字
	bipts p, Queue[MAX];
	front = 1,rear = 0;
	// 按层输入二叉树，虚结点输入0(结束符为-1)
	while((ch = convert[node]) != -1){
        node++;
		p = NULL;
		if(ch != 0){
			p = (bipts)malloc(sizeof(biTree));
			p->data = ch;
			p->lchild = p->rchild = NULL;
		}
		rear++;
		Queue[rear] = p;
		if(rear == 1){
			bt = p;
		}
		// 遇到虚结点
		else{
		// 观察发现偶数数位的数字会被insert到左边，奇数则会在右边
			if(p != NULL && Queue[front] != NULL){
				if(rear % 2 == 0){
					Queue[front]->lchild = p;
				}
				else{
					Queue[front]->rchild = p;
				}
			}
			if(rear % 2 == 1){
				front++;
			}
		}
	}
	return bt;
}

// 用inorder检测一下
int inOrderTraverse(bipts bt){
	if(bt!=NULL){
		inOrderTraverse(bt->lchild);
		printf("%d ",bt->data);
		inOrderTraverse(bt->rchild);
	}
	return 0;
}

int main(){
    int total_num;
    bipts bt;
    bt=(bipts)malloc(sizeof(biTree));
    bt=createBiTree(bt);
    inOrderTraverse(bt);
return 0;
}
