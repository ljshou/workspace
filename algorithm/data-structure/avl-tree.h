/* copyright @ L.J.SHOU Jan.20, 2014
** avl tree
*/
#ifndef AVL_TREE_H_
#define AVL_TREE_H_

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
struct AvlNode* MakeEmpty(struct AvlNode* T);
struct AvlNode* Find(ElementType x, struct AvlNode* T);
struct AvlNode* FindMin(struct AvlNode* root);
struct AvlNode* FindMax(struct AvlNode* root);
struct AvlNode* Insert(ElementType x, struct AvlNode* root);
struct AvlNode* Delete(ElementType x, struct AvlNode* root);
#endif
