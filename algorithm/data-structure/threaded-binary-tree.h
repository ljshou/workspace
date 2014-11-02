#ifndef THREADED_BINARY_TREE_H_
#define THREADED_BINARY_TREE_H_
#include <string>
using std::string;

struct ThTreeNode;

ThTreeNode* MakeTree(ThTreeNode* root);
void InOrderTraversalRecur(ThTreeNode *root);
void InOrderTraversal(ThTreeNode *root);
ThTreeNode* Destroy(ThTreeNode *root);
#endif
