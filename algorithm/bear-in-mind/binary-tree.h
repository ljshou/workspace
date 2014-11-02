// copyright @ L.J.SHOU Dec.24, 2013
// BINARY TREE
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <string>

const int MaxStackSize = 1000;

struct BinaryTreeNode 
{
  char val; 
  BinaryTreeNode *parent;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  bool visited;
};
typedef struct BinaryTreeNode TreeNode;

struct Stack
{
  TreeNode *stack[MaxStackSize];
  int top;
};

TreeNode *GetRoot(TreeNode*, const std::string&, int, int, const std::string&, int, int);
void CreateTree(TreeNode * &root);
//use PreOrder & InOrder to create BTree
void CreateTree(TreeNode * &, const std::string&, const std::string&);
void MakeTree(TreeNode * &root);
void DestroyTree(TreeNode * &root);
void SetVisited(TreeNode *root);

// O(n) space complexity
void PreOrderVisit(TreeNode * root);
void InOrderVisit(TreeNode * root);
void PostOrderVisit(TreeNode * root);

// O(n) space complexity
void PreOrderVisitStack(TreeNode * root);
void InOrderVisitStack(TreeNode *root);
void PostOrderVisitStack(TreeNode *root);

// store parent pointer 
void PreOrderVisitNoStack(TreeNode * root);
void InOrderVisitNoStack(TreeNode * root);

// Morris traversal: O(1) space complexity
void InOrderVisitMorris(TreeNode *root);

#endif
