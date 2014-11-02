#ifdef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include <iostream>
using namespace std;

template<class T>
class BinaryTreeNode
{
  friend void Visit(BinaryTreeNode<T> *); 
  friend void InOrder(BinaryTreeNode<T> *); 
  friend void PreOrder(BinaryTreeNode<T> *); 
  friend void PostOrder(BinaryTreeNode<T> *); 
  friend void LevelOrder(BinaryTreeNode<T> *); 
public:
  BinaryTreeNode():LeftChild(NULL), RightChild(NULL){}
  BinaryTreeNode(const T & e): Data(e), LeftChild(NULL),
                               RightChild(NULL){}
  BinaryTreeNode(const T& e, const BinaryTreeNode<T> *&l,
                 const BinaryTreeNode<T> *&r)
			    { Data=e; LeftChild = l; RightChild = r; } 
private:
  T Data;
  BinaryTreeNode *LeftChild, *RightChild;
};

template<class T>
void Visit(BinaryTreeNode<T> *t)
{
  cout << t->Data << " ";
}

template<class T>
void InOrder(BinaryTreeNode<T> *t)
{
  if(t){
    InOrder(t->LeftChild);
	Visit(t->data);
    InOrder(t->RightChild);
  }
}

template<class T>
void PreOrder(BinaryTreeNode<T> *t)
{
  if(t){
	Visit(t->data);
    InOrder(t->LeftChild);
    InOrder(t->RightChild);
  }
}

template<class T>
void PostOrder(BinaryTreeNode<T> *t)
{
  if(t){
    InOrder(t->LeftChild);
    InOrder(t->RightChild);
	Visit(t->data);
  }
}

#endif
