#include <stdio.h>
#include <stdlib.h>
#define	ERROR			-1
#define OVERFLOW		-2
#define	OK			1

typedef	int			elemtype;

typedef enum	{link, thread}	pointer_tag;
typedef struct tnode {
	elemtype		data;
	struct tnode		*lchild, *rchild;
	pointer_tag		ltag, rtag;
}bithrnode, *bithrtree;

bithrtree	pre;

void init_bithrtree(bithrtree *);
int create_bithrtree(bithrtree *);
int inorder_threading(bithrtree *, bithrtree );
void in_threading(bithrtree);
int inorder_traverse_thr(bithrtree, int (*visit)(bithrtree ));
int output_data(bithrtree);
void free_bithrtree(bithrtree *);

void init_bithrtree(bithrtree *bt)
{
	*bt = NULL;
}

int create_bithrtree(bithrtree *bt)
{
	elemtype	data;

	scanf("%d", &data);
	if (0 == data) {
		*bt = NULL;
	//	return OK;
	}
	else {
		*bt = (bithrtree)malloc(sizeof(bithrnode));
		if (!(*bt))
			exit(OVERFLOW);
		(*bt)->data = data;
		create_bithrtree(&(*bt)->lchild);
		create_bithrtree(&(*bt)->rchild);
	}
	return OK;
}

int inorder_threading(bithrtree *thrt, bithrtree bt)
{
	*thrt = (bithrtree) malloc (sizeof(bithrnode));
	if (!*thrt)
		exit(OVERFLOW);

	(*thrt)->ltag = link;
	(*thrt)->rtag = thread;
	(*thrt)->rchild = (*thrt);

	if (!bt)
		(*thrt)->lchild = (*thrt);
	else {
		(*thrt)->lchild = bt;
		pre = (*thrt);
		in_threading(bt);
		pre->rchild = *thrt;
		pre->rtag = thread;
		(*thrt)->rchild = pre;
	}
	return OK;
}

void in_threading(bithrtree t)
{
	if (t) {
		in_threading(t->lchild);

		if (!t->lchild) {
			t->ltag = thread;
			t->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = thread;
			pre->rchild = t;
		}
		pre = t;
		in_threading(t->rchild);
	}
}

int inorder_traverse_thr(bithrtree thrt, int (*visit)(bithrtree t))
{
	bithrtree		p;

	p = thrt->lchild;
	while (p != thrt) {
		while (p->ltag == link)
			p = p->lchild;
		visit(p);

		while (p->rtag == thread && p->rchild != thrt) {
			p = p->rchild;
			visit(p);
		}
		p = p->rchild;
	}
	return OK;
}

int output_data(bithrtree t)
{
	printf("%s\t%d\t%s\n", 	t->ltag==0 ? "link" : "thread", 
				t->data, 
				t->rtag==0 ? "link" : "thread");
	return OK;
}

void free_bithrtree(bithrtree *bt)
{
	if (*bt) {
		if ((*bt)->lchild)
			free_bithrtree(&(*bt)->lchild);
		if ((*bt)->rchild)
			free_bithrtree(&(*bt)->rchild);
		free(*bt);
		*bt = NULL;
	}
}

int main()
{
	bithrtree		thrt, bt;

	init_bithrtree(&bt);

	system("cls");		//for windows

	printf("Input elemtype to create bithrtree with preorder:\n"
		"(for exemple: 1 2 3 0 0 4 5 0 6 0 0 7 0 0 0) > ");
	if ( OK != create_bithrtree(&bt))
		return -1;

	if (OK != inorder_threading(&thrt, bt))
		return -1;

	printf("After inorder threading, traverse the threading bitree:\n");
	if (OK != inorder_traverse_thr(thrt, output_data))
		return -1;

	return 0;
} 
