/**
 * @file multi-to-binary-tree.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-17
 */

//多叉树节点
struct TreeNode {
  int child_count;
  TreeNode *child;
  int val;
};

//二叉树节点
struct BinaryTreeNode {
  BinaryTreeNode *left, *right;
  int val;
  BinaryTreeNode(int x): val(x), left(NULL), right(NULL) {}
};

BinaryTreeNode* ToBinaryTree(TreeNode *root) {
  if(root == NULL) return NULL;
  
  BinaryTreeNode *binaryRoot = new BinaryTreeNode(root->val);
  if(root->child_count == 0) return binaryRoot;

  binaryRoot->left = ToBinaryTree(root->child[0]);
  BinaryTreeNode *brother = root->left;
  for(int i=1; i<root->child_count; ++i)
  {
    brother->right = ToBinaryTree(root->child[i]);
    brother = brother->right;
  }
  return binaryRoot;
}
