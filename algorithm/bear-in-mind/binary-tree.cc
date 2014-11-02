// copyright @ L.J.SHOU Dec.24, 2013
// Binary Tree
// type num: 0
#include "binary-tree.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
using namespace std;

TreeNode *GetRoot(TreeNode *parent, const string& pre, 
     int p1, int p2, const string& in, int i1, int i2)
{
  int j;
  TreeNode *root;
  if(p2-p1+1 < 1) return NULL; // empty sub-tree
  root = new TreeNode;

  root->val = pre[p1];
  root->parent = parent;
  root->visited = false;

  for(j=i1; j<=i2; ++j)
    if(in[j] == pre[p1]) break;

  root->left = GetRoot(root, pre, p1+1, p1+j-i1, in, i1, j-1);
  root->right = GetRoot(root, pre, p1+j-i1+1, p2, in, j+1, i2);

  return root;
}

void CreateTree(TreeNode * &root)//use PreOrder & InOrder to create BTree
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

void CreateTree(TreeNode * &root, const string& pre, const string& in)
{
  if(pre.size() != in.size()){
    cerr << "Pre.size != In.size" << endl;
  }
  root = GetRoot(NULL, pre, 0, pre.size()-1, in, 0, in.size()-1);
}

void MakeTree(TreeNode * &root) 
{
  char val;
  cout << "Please input a node:" << endl;
  cin >> val;
  if(val == '*'){ //* denotes NULL
    root = NULL;
  }
  else{
    root = new TreeNode;
	root->val = val;
	MakeTree(root->left);
	MakeTree(root->right);
  }
}

void DestroyTree(TreeNode * &root)
{
  if(root)
  {
    DestroyTree(root->left);
    DestroyTree(root->right);
	delete root;
  }
  root = NULL;
}

void SetVisited(TreeNode *root)
{
  if(root)
  {
    root->visited = false;
	SetVisited(root->left);
	SetVisited(root->right);
  }
}

//////////////////////////////////////////////////
///////////////////RECURSIVELY TRAVERSE///////////
//////////////////////////////////////////////////
void PreOrderVisit(TreeNode * root)
{
  if(root)
  {
    cout << root->val << " "; 
	PreOrderVisit(root->left);
	PreOrderVisit(root->right);
  }
}

void InOrderVisit(TreeNode * root)
{
  if(root)
  {
	InOrderVisit(root->left);
    cout << root->val << " ";
	InOrderVisit(root->right);
  }
}

void PostOrderVisit(TreeNode * root)
{
  if(root)
  {
	PostOrderVisit(root->left);
	PostOrderVisit(root->right);
    cout << root->val << " "; 
  }
}

//////////////////////////////////////////////////
///////////////////TRAVERSE USING STACK///////////
//////////////////////////////////////////////////
void PreOrderVisitStack(TreeNode * root)
{ //using stack to pre_order_visit BTree
  Stack s;
  s.top = -1;
  while(root != NULL || s.top != -1)
  {
    while(root)
	{
	  cout << root->val << " ";
	  s.stack[++(s.top)] = root;
	  root = root->left;
	}
	if(s.top != -1)
	{
	  root = s.stack[s.top --];
	  root = root->right;
	}
  }
}

void PreOrderVisitStack2(TreeNode *root)
{
  stack<TreeNode*> s;
  if(root)
  {
    s.push(root);
	while(!s.empty())
	{
	  root = s.top();
	  s.pop();
	  cout << root->val << " ";
	  // push right child first
	  if(root->right)
	    s.push(root->right);
	  if(root->left)
	    s.push(root->left);
	}
  }
}


void InOrderVisitStack(TreeNode *root)
{
  Stack s;
  s.top = -1;
  while(root != NULL || s.top != -1)
  {
    while(root)
	{
	  s.stack[++(s.top)] = root;
	  root = root->left;
	}
	if(s.top != -1)
	{
	  root = s.stack[(s.top)--];
	  cout << root->val << " ";
	  root = root->right;
	}
  }
}

void PostOrderVisitStack(TreeNode *root)//非递归，用stack
{
  Stack s;
  s.top = -1;
  while(root || s.top != -1)
  {
    while(root && !root->visited) 
	{
	  s.stack[++(s.top)] = root; 
	  root = root->left;
	}
	while(s.top != -1)
	{//栈顶元素的左孩子要么NULL,要么已经被访问，所以只考虑右孩子即可
	  root = s.stack[(s.top)--];
	  if(root->visited  == false)//若没被访问，先处理右孩子
	  {
	    s.stack[++(s.top)] = root;
	    root->visited = true;
	    root = root->right;
		break;
	  }
	  else{//右孩子已经处理完，Visit即可
	    cout << root->val << " ";
		root = NULL;
	  }
    }
  }
}

void PostOrderVisitStack2(TreeNode *root)
{
  stack<TreeNode*> s;
  TreeNode *p(NULL);
  while(root || !s.empty())
  {
    while(root){
	  s.push(root);
	  root = root->left;
	}
	p = NULL;//previously visited node
	while(!s.empty())
	{
	  root = s.top(); 
	  s.pop();
	  assert(root);
	  if(root->right == p){
	    //right is NULL or visited
		cout << root->val << " ";
		p = root;
		root = NULL;
	  }
	  else{//push this node again into stack
	    s.push(root);
		root = root->right;
		break;
	  }
	}
  }
}

//////////////////////////////////////////////////////////
///////////////////TRAVERSE NO STACK//////////////////////
//////////////////////////////////////////////////////////
void PreOrderVisitNoStack(TreeNode * root)//非递归，不用栈
{
  while(root != NULL)
  {
	if(!root->visited){
      cout << root->val << " ";
	  root->visited = true;
	}
    while(root->left && !root->left->visited)
	{
	  root = root->left;
      cout << root->val << " ";
	  root->visited = true;
	}
	if(root->right !=NULL && !root->right->visited)
	{
	  root = root->right;
	}
	else
	  root = root->parent;
  }
}

// use parent pointer to avoid dependence of stack
void InOrderVisitNoStack(TreeNode * root)
{
  while(root != NULL)
  {
    while(root->left && !root->left->visited)
	{
	  root = root->left;
	}
	if(!root->visited)
	{
	  cout << root->val << " ";
	  root->visited = true;
	}
	if(root->right !=NULL && !root->right->visited)
	{
	  root = root->right;
	}
	else
	  root = root->parent;
  }
}

//////////////////////////////////////////////////////////
///////////////////MORRIS TRAVERSE////////////////////////
//////////////////////////////////////////////////////////
void PreOrderVisitMorris(TreeNode *root)
{
  TreeNode *pre(NULL);
  while(root)
  {
	if(root->left == NULL){
      cout << root->val << " ";
	  root = root->right;
	  continue;
	}
	// find the precessor of root
	for(pre = root->left; pre->right && pre->right != root; pre = pre->right) {}
	if(pre->right == NULL){
      cout << root->val << " ";
	  pre->right = root;
	  root = root->left;
	}
	else{
	  pre->right = NULL;
	  root = root->right;
	}
  }
}

void InOrderVisitMorris(TreeNode *root)
{
  TreeNode *pre(NULL);  
  while(root)
  {
    if(root->left == NULL){
	  cout << root->val << " ";
	  root = root->right;
	  continue;
	}
	// find the precessor of root
	for(pre = root->left; pre->right && pre->right != root; pre = pre->right);

	if(pre->right == NULL){
	  pre->right = root;
	  root = root->left;
	}
	else{
	  pre->right = NULL;
	  cout << root->val << " ";
	  root = root->right;
	}
  }
}

vector< vector<char> > levelOrder(TreeNode *root) 
{
      queue<TreeNode*> q1, q2;
      vector< vector<char> > result;
      vector<char> level;
      TreeNode *node(NULL);
      
      if(root == NULL) return result;
      q1.push(root);
      while(!q1.empty() || !q2.empty())
      {
        level.clear();
        while(!q1.empty()){
          node = q1.front();
          q1.pop();
          level.push_back(node->val);
          if(node->left) q2.push(node->left);
          if(node->right) q2.push(node->right);
        }
        if(!level.empty()) result.push_back(level);
        level.clear();

        while(!q2.empty()){
          node = q2.front();
          q2.pop();
          level.push_back(node->val);
          if(node->left) q1.push(node->left);
          if(node->right) q1.push(node->right);
        }
        if(!level.empty()) result.push_back(level);
      }
      return result;
}

int main()
{
  TreeNode *root;
  string pre("ABDEGHJCFI"), in("DBGEHJACIF"); 
  CreateTree(root, pre, in);

  cout << "PreOrderVisit: " << endl;
  PreOrderVisit(root);
  cout << endl;
  PreOrderVisitStack2(root);
  cout << endl;
  PreOrderVisitNoStack(root);
  SetVisited(root);
  cout << endl;
  PreOrderVisitMorris(root);

  cout << endl << "InOrderVisit: " << endl;
  InOrderVisit(root);
  cout << endl;
  InOrderVisitStack(root);
  cout << endl;
  InOrderVisitNoStack(root);
  cout << endl << "Morris: " << endl;
  InOrderVisitMorris(root);
  cout << endl;

  SetVisited(root);
  PostOrderVisitStack2(root);
  cout << endl;

  //level order
  cout << "Level Order" << endl;
  vector< vector<char> > result;
  result = levelOrder(root);
  for(int i=0; i<result.size(); ++i)
  {
    for(int j=0; j<result[i].size(); ++j)
	  cout << result[i][j] <<  " ";
	cout << endl;
  }
  DestroyTree(root);
  return 0;
}
