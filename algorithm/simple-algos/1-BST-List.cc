//copyright @ L.J.SHOU Feb.15, 2014
//convert a binary-search-tree to a double-linked list
// 不能用 morris traversal
#include "build-binary-tree.h"
#include <iostream>
#include <stack>
using namespace std;

/**
* struct TreeNode{
*  TreeNode *left;
*  TreeNode *right;
*  int val;
*  TreeNode(int x)
*    :val(x), left(NULL), right(NULL){}
* };
*/

TreeNode* Convert(TreeNode *root)
{ /* exit */
  if(root == NULL) return root;

  if(root->right){
    root->right = Convert(root->right);
  }

  if(root->left){
    TreeNode *leftHead = Convert(root->left);
    TreeNode *leftRear = leftHead;
    for(; leftRear->right; leftRear = leftRear->right);

    /* merge */
    leftRear->right = root;
    root->left = leftRear;
    root = leftHead;
  }

  return root;
}

TreeNode *ConvertNonRecur(TreeNode *root)
{
  TreeNode *head(NULL), *rear(NULL);
  stack<TreeNode*> s;

  while(root || !s.empty())
  {
    while(root){
	  s.push(root);
	  root = root->left;
	}
	root = s.top(); s.pop();
	TreeNode *next = root->right;

	//insert root into double-linked-list
	if(rear){
	  root->right = rear->right;
	  rear->right = root;
	  root->left = rear;
	  rear = rear->right;
	}
	else{
	  head = rear = root;
	  head->right = head->left = NULL; 
	}
	root = next;
  }

  return head;
}

int main(void)
{
  TreeNode *root(NULL);
  string pre("421356");
  string in("123456");
  root = CreateTree(pre, in);
  
  //InOrder(root); cout << endl;
  root = ConvertNonRecur(root);

  for(TreeNode *p=root; p; p=p->right)
    cout << p->val << " ";
  cout << endl;

  //delete double linked-list
  TreeNode *next(NULL);
  #if 0
  for(; root; root = root->right){
    next = root->right; 
	cout << root->val << endl;
	delete root;
	root = next;
  }
  #endif
  while(root){
    next = root->right;
	delete root;
	root = next;
  }
  //root = DestroyTree(root);
  return 0;
}
