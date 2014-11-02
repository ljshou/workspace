/**
 * copyright @ L.J.SHOU Feb.10, 2014
 * threaded binary tree
*/
#include "threaded-binary-tree.h"
#include <iostream>
#include <cstring>
#include <cassert>
using std::cout;
using std::cin;
using std::string;
using std::endl;

typedef enum {THREAD, LINK } PointerFlag;

struct ThTreeNode{
  char val;
  ThTreeNode *left;
  ThTreeNode *right;
  PointerFlag l_tag; 
  PointerFlag r_tag;
  ThTreeNode()
    :left(NULL), right(NULL), l_tag(LINK), r_tag(LINK){}
};

// global variant: previous visited node
ThTreeNode *g_pre(NULL);

ThTreeNode *GetRoot(ThTreeNode *parent, const std::string& pre, 
                 int p1, int p2, const std::string& in, int i1, int i2)
{
  int j;
  ThTreeNode *root(NULL);

  if(p2-p1+1 < 1) return NULL; // empty sub-tree
  root = new ThTreeNode;
  root->val = pre[p1];

  for(j=i1; j<=i2; ++j)
    if(in[j] == pre[p1]) break;

  root->left  = GetRoot(root, pre, p1+1, p1+j-i1, in, i1, j-1);
  root->right = GetRoot(root, pre, p1+j-i1+1, p2, in, j+1, i2);

  return root;
}


void InThreading(ThTreeNode *root)
{
  if(root == NULL) return;

  InThreading(root->left);

  if(g_pre->right == NULL){
    g_pre->r_tag = THREAD;
	g_pre->right = root;
  }
  if(root->left == NULL){
    root->l_tag = THREAD;
	root->left = g_pre;
  }
  g_pre = root;

  InThreading(root->right);
}

ThTreeNode* InOrderThreading(ThTreeNode *root)
{
  ThTreeNode *head(NULL);

  //头节点
  head = new ThTreeNode();
  head->l_tag = LINK;
  head->r_tag = THREAD;
  if(root == NULL) head->left = head;
  else{
    head->left = root; g_pre = head;
	InThreading(root);
	g_pre->right = head; g_pre->r_tag = THREAD;
	head->right = g_pre; //head->right指向中序遍历最后一个节点 
  }

  return head;
}

ThTreeNode* MakeTree(ThTreeNode* root)
{
  std::string pre, in;

  do{
    cout << "Please Input the PreOrderVisit Result:" << endl;
    cin >> pre;
    cout << "Please Input the InOrderVisit Result:" << endl;
    cin >> in;
  }while (pre.size() != in.size());

  root = GetRoot(NULL, pre, 0, pre.size()-1, in, 0, in.size()-1);
  // inorder threading
  root = InOrderThreading(root);

  return root;
}

void InOrderTraversalRecur(ThTreeNode *root)
{
  if(root == NULL) return;

  InOrderTraversalRecur(root->left);
  cout << root->val << " ";
  InOrderTraversalRecur(root->right);
}

void InOrderTraversal(ThTreeNode *root)
{
  ThTreeNode *p = root->left; // p 指向根节点

  while(p != root){
    while(p->l_tag == LINK) p = p->left;
	cout << p->val << " ";

	while(p->r_tag == THREAD && p->right != root){
	  p = p->right;
	  cout << p->val << " ";
	}

	p = p->right;
  }
}

ThTreeNode* Destroy(ThTreeNode *root)
{
  if(root){
    if(root->l_tag == LINK)
      root->left  = Destroy(root->left);
    if(root->r_tag == LINK)
      root->right = Destroy(root->right);
	delete root;
  }
  return NULL;
}

int main(void)
{
  ThTreeNode *root(NULL);

  root = MakeTree(root);

  InOrderTraversal(root);
  cout << endl;

  root = Destroy(root);

  return 0;
}
