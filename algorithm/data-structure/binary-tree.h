// copyright @ L.J.SHOU Jan.13, 2014
// three versions of BinaryTree Traversal

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <string>
using std::string;

struct TreeNode;

TreeNode *GetRoot(TreeNode*, const string&, int, int, const string&, int, int);
void CreateTree(TreeNode * &root);
void CreateTree(TreeNode * &, const string&, const string&);
void MakeTree(TreeNode * &root);
void DestroyTree(TreeNode * &root);
void SetVisited(TreeNode *root);

//recusive
void PreOrderVisit(TreeNode *root);
void InOrderVisit(TreeNode *root);
void PostOrderVisit(TreeNode *root);

//interative(stack)
void PreOrderVisitStack(TreeNode *root);
void InOrderVisitStack(TreeNode *root);
void PostOrderVisitStack(TreeNode *root);

//interative(no stack)
void PreOrderVisitNoStack(TreeNode *root);
void InOrderVisitNoStack(TreeNode *root);
void PostOrderVisitNoStack(TreeNode *root);

//morris traversal: O(1) space complexity
void InOrderVisitMorris(TreeNode *root);

#endif
