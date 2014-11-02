// copyrigth @ L.J.SHOU Mar.09, 2014
// find the mirror of a binary tree
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x)
    :val(x), left(NULL), right(NULL){}
};

// recursive version
TreeNode* Mirror(TreeNode *root)
{
  if(root == NULL)
    return NULL;

  swap(root->left, root->right);
  root->left = Mirror(root->left);
  root->right = Mirror(root->right);

  return root;
}

// iterative version 1
// pre-order traversal
TreeNode* MirrorIterative(TreeNode *root)
{
  if(root == NULL) return NULL;

  TreeNode *p = root;
  stack<TreeNode*> s;
  while(p || !s.empty())
  {
    while(p){
	  swap(p->left, p->right);
	  s.push(p);
	  p = p->left;
	}
    p = s.top(); s.pop();
	p = p->right;
  }
  return root;
}

// iterative version 2
// level order traversal
TreeNode* MirrorLevelOrder(TreeNode *root)
{
  if(root == NULL) return NULL;

  TreeNode *node(NULL);
  queue<TreeNode *> cur, next;
  cur.push(root);

  while(!cur.empty())
  {
    while(!cur.empty()){
	  node = cur.front(); cur.pop(); 
	  swap(node->left, node->right);
	  if(node->left) 
	    next.push(node->left);
	  if(node->right) 
	    next.push(node->right);
	}
	swap(cur, next);
  }
  return root;
}

TreeNode* Destroy(TreeNode *root)
{
  if(root == NULL) return NULL;
  root->left = Destroy(root->left);
  root->right = Destroy(root->right);
  delete root;
  return NULL;
}

void InOrder(TreeNode *root)
{
  stack<TreeNode*> s;

  while(root || !s.empty()){
    while(root){
	  s.push(root);
	  root = root->left;
	}
	root = s.top(); s.pop();
	cout << root->val << " ";
	root = root->right;
  }
  cout << endl;
}

int main(void)
{
  TreeNode *root(NULL);

  root = new TreeNode(8);
  root->left = new TreeNode(6);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(11);

  root = MirrorLevelOrder(root);
  InOrder(root);
  LevelOrder(root);
  
  root = Destroy(root);
  return 0;
}
