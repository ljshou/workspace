#ifndef BUILD_BINARY_TREE_H_ 
#define BUILD_BINARY_TREE_H_ 
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x)
    :val(x), left(NULL), right(NULL){}
};

//p2-p1+1 must equals to i2-i1+1
TreeNode *GetRoot(string::const_iterator pre_begin, string::const_iterator pre_end,
                  string::const_iterator in_begin, string::const_iterator in_end)
{
  if(pre_begin == pre_end) return NULL;
  TreeNode *root(NULL);
  root = new TreeNode(*pre_begin - '0');

  int i=0;
  string::const_iterator it = in_begin;
  for(; *it != *pre_begin; ++it, ++i);

  root->left  = GetRoot(pre_begin+1, pre_begin+i+1, in_begin, in_begin+i);
  root->right = GetRoot(pre_begin+i+1, pre_end, it+1, in_end);

  return root;
}

TreeNode* CreateTree()//use PreOrder & InOrder to create BTree
{
  string pre, in;
  do{
    cout << "Please Input the PreOrderVisit Result:" << endl;
    cin >> pre;
    cout << "Please Input the InOrderVisit Result:" << endl;
    cin >> in;
  }while(pre.size() != in.size());

  return GetRoot(pre.begin(), pre.end(), in.begin(), in.end());
}

TreeNode* CreateTree(const string& pre, const string& in)
{
  if(pre.size() != in.size()){
    cerr << "Pre.size != In.size" << endl;
  }
  return GetRoot(pre.begin(), pre.end(), in.begin(), in.end());
}

TreeNode* DestroyTree(TreeNode *root)
{
  if(root)
  {
    root->left = DestroyTree(root->left);
    root->right = DestroyTree(root->right);
	delete root;
  }
  return NULL;
}

void InOrder(TreeNode *root)
{
  if(root){
    InOrder(root->left);
	cout << root->val << " ";
	InOrder(root->right);
  }
}

#endif
