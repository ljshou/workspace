#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x=0)
   : val(x), left(NULL), right(NULL){}
};

TreeNode* BuildSearchTree(int *A, int left, int right)
{
  if(left > right) return NULL;
  if(left == right) return new TreeNode(A[left]);

  int mid = left + (right-left)/2;
  TreeNode *root(NULL);
  root = new TreeNode(A[mid]);
  root->left = BuildSearchTree(A, left, mid-1);
  root->right = BuildSearchTree(A, mid+1, right);

  return root;
}

int main(void)
{
}
