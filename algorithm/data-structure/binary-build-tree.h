#ifndef BINARY_BUILD_TREE_H_
#define BINARY_BUILD_TREE_H_
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

struct TreeNode 
{
  char value; 
  TreeNode *parent;
  TreeNode *left_child;
  TreeNode *right_child;
  bool visited;
};

TreeNode *GetRoot(TreeNode *parent, const string& pre, int p1, int p2, const string& in, int i1, int i2)
{
  int j;
  TreeNode *root;
  if(p2-p1+1 < 1) return NULL; // empty sub-tree
  root = new TreeNode;

  root->value = pre[p1];
  root->parent = parent;
  root->visited = false;

  for(j=i1; j<=i2; ++j)
    if(in[j] == pre[p1]) break;

  root->left_child = GetRoot(root, pre, p1+1, p1+j-i1, in, i1, j-1);
  root->right_child = GetRoot(root, pre, p1+j-i1+1, p2, in, j+1, i2);

  return root;
}

void CreateTree(struct TreeNode * &root)//use PreOrder & InOrder to create BTree
{
  string pre, in;
  do{
    cout << "Please Input the PreOrderVisit Result:" << endl;
    cin >> pre;
    cout << "Please Input the InOrderVisit Result:" << endl;
    cin >> in;
  }while(pre.size() != in.size());
  root = GetRoot(NULL, pre, 0, pre.size()-1, in, 0, in.size()-1);
}

void CreateTree(struct TreeNode * &root, const string& pre, const string& in)
{
  if(pre.size() != in.size()){
    cerr << "Pre.size != In.size" << endl;
  }
  root = GetRoot(NULL, pre, 0, pre.size()-1, in, 0, in.size()-1);
}

void MakeTree(TreeNode * &root) 
{
  char value;
  cout << "Please input a node:" << endl;
  cin >> value;
  if(value == '*') //* denotes NULL
  {
    root = NULL;
  }
  else
  {
    root = new struct TreeNode;
	  root->value = value;
	  MakeTree(root->left_child);
	  MakeTree(root->right_child);
  }
}

void DestroyTree(TreeNode * &root)
{
  if(root)
  {
    DestroyTree(root->left_child);
    DestroyTree(root->right_child);
	delete root;
  }
  root = NULL;
}

#endif
