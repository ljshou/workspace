#include <stdio.h>
#include <stdlib.h>
#include "thrbitree.h"

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

