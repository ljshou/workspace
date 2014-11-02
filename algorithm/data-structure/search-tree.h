// copyright @ L.J.SHOU Nov.8, 2013
// Binary Search Tree
#ifndef SEARCH_TREE_H_
#define SEARCH_TREE_H_

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;
typedef Position SearchTree;

TreeNode* Destroy(TreeNode *root);
TreeNode* Insert(TreeNode *root, ElementType x);
TreeNode* Delete(TreeNode *root, ElementType x);

TreeNode* Find(TreeNode* root, ElementType x);
ElementType Retrieve(TreeNode *p);

TreeNode* FindMin(TreeNode *root);
TreeNode* FindMax(TreeNode *root);

void InOrderVisit(TreeNode *root);
int  Height(TreeNode *root);

#endif
