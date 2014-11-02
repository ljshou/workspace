#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include "binarytreenode.h"

template <class T>
class BinaryTree
{
 public:
  BinaryTree():root(NULL){}
  ~BinaryTree(){}
  bool IsEmpty()
      {return ((root)?false:true);}
  bool Root(T& x) const;
  void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
  void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
  void PreOrder(void (*Visit)(BinaryTreeNode<T> *u))
      {PreOrder(Visit, root);}
  void InOrder(void (*Visit)(BinaryTreeNode<T> *u))
      {InOrder(Visit, root);}
  void PostOrder(void (*Visit)(BinaryTreeNode<T> *u))
      {PostOrder(Visit, root);}
  void LevelOrder(void (*Visit)(BinaryTreeNode<T> *u));

 private:
  BinaryTreeNode<T> *root;
  void PreOrder(void (*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T> *t);
  void InOrder(void (*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T> *t);
  void PostOrder(void (*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T> *t);
};


#endif
