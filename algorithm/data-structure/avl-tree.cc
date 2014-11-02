/* AVLTree implemented by L.J. in Nov.17, 2013 */
#include "avl-tree.h"
#include<iostream>
using namespace std;

struct AvlNode
{
  ElementType element;
  AvlNode *left;
  AvlNode *right;
  int height;
};

static int Height(struct AvlNode* root)
//static means this function is accessable only in this file
{
  if(root == NULL)
    return -1;
  else
    return root->height;
}

static int Max(const int &a, const int &b)
{
  return a>b?a:b;
}

//This function can be called only if k2 has a left child
//perform a rotate between a node(k2) and its left child
//update heights, and then return new root
static Position SingleRotateWithLeft(Position k2)
{
  Position k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
  k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
  return k1;
}

//This function can be called only if k2 has a right child
//perform a rotate between a node(k2) and its right child
//update heights, and then return new root
static Position SingleRotateWithRight(Position k2)
{
  Position k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;

  k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
  k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
  return k1;
}

//This function can be called only if k3 has a left child: k1
//and k3's left child has a right child: k2
//Do the left-right double rotation
//update heights, and then return new root
static Position DoubleRotateWithLeft(Position k3)
{
  //rotate between k1 and k2
  k3->left = SingleRotateWithRight(k3->left);
  //rotate between k2 and k3
  k3 = SingleRotateWithLeft(k3);
  return k3;
}

//This function can be called only if k3 has a right child k1
//and k3's left child has a left child: k2
//Do the left-right double rotation
//update heights, and then return new root
static Position DoubleRotateWithRight(Position k3)
{
  k3->right = SingleRotateWithLeft(k3->right);
  k3 = SingleRotateWithRight(k3);
  return k3;
}

AvlTree MakeEmpty(AvlTree t)
{
  if(t)
  {
    t->left = MakeEmpty(t->left);
    t->right = MakeEmpty(t->right);
	delete t;
  }
  return NULL;
}

Position Find(ElementType x, AvlTree t)
{
  if(t == NULL)
  {
    cerr << "Element not found" << endl;
	return NULL;
  }
  if(x < t->element)
    return Find(x, t->left);
  else if(x > t->element)
    return Find(x, t->right);
  else
    return t;
}

Position FindMin(AvlTree t)
{//recursive
  if(t == NULL || t->left == NULL) return t;
  else  return FindMin(t->left);
}

Position FindMax(AvlTree t)
{//non-recursive
  while(t && t->left)
  {
    t = t->left;
  }
  return t;
}

AvlTree Insert(ElementType x, AvlTree t)
{
  if(t == NULL)
  {
    t = new struct AvlNode;
	t->element = x;
	t->left = t->right = NULL;
	t->height = 0;
  }
  else if(x < t->element)
  {
    t->left = Insert(x, t->left);
	if(Height(t->left) - Height(t->right) == 2)
	{
	  if(x < t->left->element)
	    t = SingleRotateWithLeft(t);
	  else
	    t = DoubleRotateWithLeft(t);
	}
  }
  else if(x > t->element)
  {
    t->right = Insert(x, t->right);
	if(Height(t->right) - Height(t->left) == 2)
	{
	  if(x > t->right->element)
	    t = SingleRotateWithRight(t);
	  else
	    t = DoubleRotateWithRight(t);
	}
  }
  //else x is already in the tree, we'll do nothing
  t->height = Max(Height(t->left), Height(t->right)) + 1;
  return t;
}

AvlTree Delete(ElementType x, AvlTree t)
{//TODO
}

int main()
{
  AvlTree t(NULL);
  int a[]={2,1,4,5,9,3,6,7};
  for(int i=0; i<sizeof(a)/sizeof(int); ++i)
    t = Insert(a[i], t);  
  cout << "Tree height: " << t->height << endl;
  t = MakeEmpty(t);
  return 0;
}
