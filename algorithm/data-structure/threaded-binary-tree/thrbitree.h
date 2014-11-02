#ifndef BITHRTREE_H_H_H_
#define BITHRTREE_H_H_H_

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

#endif
