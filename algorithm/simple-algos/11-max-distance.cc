// copyright @ L.J.SHOU Mar.04, 2014
// max distance in a binary tree
#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x)
  :val(x), left(NULL), right(NULL){}
};

int Depth(TreeNode *root)
{
  if(root == NULL)
    return -1;
  return 1 + max(Depth(root->left), Depth(root->right));
}

int MaxDistance(TreeNode *root)
{
  if(root == NULL)
    return 0;
  return 2 + Depth(root->left) + Depth(root->right);
}

TreeNode* Destroy(TreeNode *root)
{
  if(root == NULL)
    return NULL;

  root->left = Destroy(root->left);
  root->right = Destroy(root->right);
  delete root;

  return NULL;
}

int main(void)
{
  TreeNode *root(NULL);
  root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->left = new TreeNode(2);
  //root->right = new TreeNode(4);

  cout << MaxDistance(root) << endl;

  root = Destroy(root);
  return 0;
}
