// copyright @ L.J.SHOU Nov.8, 2013
// Binary Search Tree

#include "search-tree.h"
#include "binary-tree-printer.h"
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

const int N=10;
const int M=10;
typedef int ElementType;

/*
struct TreeNode
{
  ElementType val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(ElementType x)
    : val(x), left(NULL), right(NULL){}
};
*/

TreeNode* Destroy(TreeNode *t)
{
  if(t != NULL)
  {
    t->left = Destroy(t->left);
    t->right = Destroy(t->right);
	delete t;
  }

  return NULL;
}

int Height(TreeNode *t)
{
  if(t == NULL) 
    return -1;

  int left  = Height(t->left); 
  int right = Height(t->right); 

  if(left > right) 
    return left + 1;
  else 
    return right + 1;
}

TreeNode* Find(TreeNode *t, ElementType x)
{
  if(t != NULL)
  {
    if(x < t->val)
	  return Find(t->left, x);
    else if(x > t->val)
	  return Find(t->right, x);
	else
	  return t;
  }
  return NULL;
}

TreeNode* FindMin(TreeNode *t)
{ // iterative
  TreeNode* p = t;

  while(p && p->left)
    p = p->left;

  return p;
}

TreeNode* FindMax(TreeNode* t)
{ // recursive
  if(t == NULL) 
    return NULL;
  else if(t->right == NULL)
    return t;
  else
    return FindMax(t->right);
}

TreeNode* Insert(TreeNode* t, ElementType x)
{ // recursive
  if(t == NULL)
  {
    t = new TreeNode;
	t->val = x;
	t->left = t->right = NULL;
  }
  else if(x < t->val)
    t->left = Insert(t->left, x);
  else if(x > t->val)
    t->right = Insert(t->right, x);
  /* else x is already in the tree; 
      we'll do nothing */
  return t;
}

TreeNode* Delete(TreeNode* t, ElementType x)
{ /* recursive */
  TreeNode* p(NULL);

  if(t == NULL)
    cerr << "Element " << x << " Not Found" << endl;
  else{
    if(x < t->val)
	  t->left = Delete(t->left, x);
	else if(x > t->val)
	  t->right = Delete(t->right, x);
	else
	{ /* t->val = x */
	  if(t->left && t->right)
	  { /* two children */
	    /* find min in the right sub-tree */
	    p = FindMin(t->right);
		t->val = p->val;
		t->right = Delete(t->right, t->val);
	  }
	  else
	  { /* one or no child */
	    p = t;
		if(t->left == NULL)
		  t = t->right;
		else if(t->right == NULL)
		  t = t->left;
		delete p;
	  }
	}
  }
  return t;
}

void PreOrderVisit(TreeNode* t)
{
  if(t)
  {
	cout << t->val << " ";
    PreOrderVisit(t->left);
    PreOrderVisit(t->right);
  }
}

void InOrderVisit(TreeNode* t)
{
  if(t)
  {
    InOrderVisit(t->left);
	cout << t->val << " ";
    InOrderVisit(t->right);
  }
}

void LevelOrderVisit(TreeNode* t)
{
  if(t == NULL) return;

  TreeNode *node(NULL);
  queue<TreeNode* > q;
  q.push(t);

  while(!q.empty())
  {
	node = q.front(); q.pop();
    cout << node->val << " ";
	if(node->left)
	  q.push(node->left);
	if(node->right)
	  q.push(node->right);
  }
}

int main()
{
  TreeNode* t(NULL);
  
  srand(time(0));
  for(int i=0; i<N; ++i)
    t = Insert(t, rand()%M+1);

  cout << "PreOrder: ";
  PreOrderVisit(t);
  cout << endl;

  cout << "InOrder: ";
  InOrderVisit(t);
  cout << endl;

  cout << "LevelOrder: ";
  LevelOrderVisit(t);
  cout << endl;

  cout << "Height: " << Height(t) << endl;
  cout << "Min: " << FindMin(t)->val << endl;
  cout << "Max: " << FindMax(t)->val << endl;

  PrintBinaryTree(t);
  t = Destroy(t);
  return 0;
}
