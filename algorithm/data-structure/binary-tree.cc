// copyright @ L.J.SHOU Nov.2013
// binary tree traversal

#include "binary-tree.h"
#include "binary-build-tree.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/**
* struct TreeNode 
* {
*   char value; 
*   TreeNode *parent;
*   TreeNode *left_child;
*   TreeNode *right_child;
*   bool visited; //标记是否已访问
* };
*/

void SetVisited(TreeNode *root)
{
  if(root){
    root->visited = false;
	SetVisited(root->left_child);
    SetVisited(root->right_child);
  }
}

/**************************************************/
/**************************************************/
void PreOrderVisit(struct TreeNode * root)
{
  if(root){
    cout << root->value << " "; 
	PreOrderVisit(root->left_child);
	PreOrderVisit(root->right_child);
  }
}

void InOrderVisit(struct TreeNode * root)
{
  if(root)
  {
	InOrderVisit(root->left_child);
    cout << root->value << " ";
	InOrderVisit(root->right_child);
  }
}

void PostOrderVisit(struct TreeNode * root)
{
  if(root)
  {
	PostOrderVisit(root->left_child);
	PostOrderVisit(root->right_child);
    cout << root->value << " "; 
  }
}
/**************************************************/
/**************************************************/

/**************************************************/
/**************************************************/
void PreOrderVisitStack(struct TreeNode * root)
{ 
  stack<TreeNode*> s;

  while(root != NULL || !s.empty())
  {
    while(root){
	  cout << root->value << " ";
	  s.push(root);
	  root = root->left_child;
	}
	if(!s.empty()){
	  root = s.top(); s.pop();
	  root = root->right_child;
	}
  }
}

void InOrderVisitStack(TreeNode *root)
{
  stack<TreeNode*> s;

  while(root != NULL || !s.empty())
  {
    while(root){
	  s.push(root);
	  root = root->left_child;
	}
	if(!s.empty()){
	  root = s.top(); s.pop();
	  cout << root->value << " ";
	  root = root->right_child;
	}
  }
}

void PostOrderVisitStack(TreeNode *root)
{
  stack<TreeNode*> s;
  TreeNode *pre(NULL); //前一部访问的节点

  while(root || !s.empty())
  {
    while(root){
	  s.push(root);
	  root = root->left_child;
	}

	if(!s.empty()){
	  root = s.top(); s.pop();
	  // right_child already visited
	  if(root->right_child == pre || root->right_child == NULL){
	    cout << root->value << " ";
		pre = root;
		root = NULL;
	  }
	  else{
	    s.push(root);
	    root = root->right_child;
	  }
	}
  }//end while
}
/**************************************************/

/**************************************************/
void PreOrderVisitNoStack(TreeNode * root)//非递归，不用栈
{
  while(root != NULL)
  {
	if(!root->visited){
      cout << root->value << " ";
	  root->visited = true;
	}
    while(root->left_child && !root->left_child->visited)
	{
	  root = root->left_child;
      cout << root->value << " ";
	  root->visited = true;
	}
	if(root->right_child !=NULL && !root->right_child->visited)
	{
	  root = root->right_child;
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
    while(root->left_child && !root->left_child->visited)
	{
	  root = root->left_child;
	}
	if(!root->visited)
	{
	  cout << root->value << " ";
	  root->visited = true;
	}
	if(root->right_child !=NULL && !root->right_child->visited)
	{
	  root = root->right_child;
	}
	else
	  root = root->parent;
  }
}

void PostOrderVisitNoStack(TreeNode *root)
{
  while(root)
  {
    while(root->left_child && !root->left_child->visited){
	  root = root->left_child;
	}
	//右子树未访问
    if(root->right_child && !root->right_child->visited){
	  root = root->right_child;
	}
	else{
	  cout << root->value << " ";
	  root->visited = true;
	  root = root->parent;
	}
  }
}

/**************************************************/
//Morris Traversal
//space effienct
void PreOrderVisitMorris(TreeNode *root)
{
  TreeNode *pre(NULL);

  while(root)
  {
    if(root->left_child == NULL){
	  cout << root->value << " ";  
	  root = root->right_child;
	  continue;
    }	
	//find the precessor of root
	TreeNode *node = root->left_child;
	for(; node->right_child && node->right_child != root; node = node->right_child);
	//第一次访问
	if(node->right_child == NULL){
	  node->right_child = root; //建立线索
	  cout << root->value << " ";
	  root = root->left_child;
	}
	else{
	  node->right_child = NULL;
	  root = root->right_child;
	}
  }

}

void InOrderVisitMorris(TreeNode *root)
{
  TreeNode *pre(NULL);  
  while(root)
  {
	// 左子树是空，直接访问该节点，然后访问右子树
    if(root->left_child == NULL){
	  cout << root->value << " ";
	  root = root->right_child;
	  continue;
	}
	// 找 root 的前驱节点
	for(pre = root->left_child; pre->right_child && pre->right_child != root; pre = pre->right_child);

	// 第一次访问root, 建立线索
	if(pre->right_child == NULL){
	  pre->right_child = root;
	  root = root->left_child;
	}
	// 第二次访问，说明左子树已经访问过
	else{
	  pre->right_child = NULL;
	  cout << root->value << " ";
	  root = root->right_child;
	}
  }
}

void reverse(TreeNode *from, TreeNode *to) 
{
  //reverse from to to like a linked list
  TreeNode *head(nullptr);
  TreeNode *cur(from), *next(nullptr);
  while(cur) {
    next = cur->right_child;
    cur->right_child = head;
    head = cur;
    cur = next;
  }
}

void visit_reverse(TreeNode *from, TreeNode *to) 
{
  reverse(from, to);
  TreeNode *cur(to);
  while(cur) {
    cout << cur->value << " ";
    cur = cur->right_child;
  }
  reverse(to, from);
}

void PostOrderVisitMorris(TreeNode *root)
{
  TreeNode dummy;
  dummy.left_child = root;
  dummy.right_child = nullptr;
  root = &dummy;

  while(root) {
    if(root->left_child == nullptr) {
      root = root->right_child;
      continue;
    }
    //find the right_child most node of left_child sub-tree
    TreeNode *temp = root->left_child;
    for(; temp->right_child!=nullptr && temp->right_child!=root; temp=temp->right_child);
    if(temp->right_child == nullptr) {
      temp->right_child = root;
      root = root->left_child;
    }
    else {
      temp->right_child = nullptr;
      visit_reverse(root->left_child, temp);
      root = root->right_child;
    }
  }
}

int main()
{
  TreeNode *root;
  string pre("ABDEGHJCFI"), in("DBGEHJACIF"); 
  CreateTree(root, pre, in);

  cout << "PreOrderVisit: " << endl;
  PreOrderVisit(root); cout << endl;
  PreOrderVisitStack(root); cout << endl;
  PreOrderVisitNoStack(root); cout << endl;
  PreOrderVisitMorris(root); cout << endl;
  cout << endl;

  SetVisited(root);
  cout << "InOrderVisit: " << endl;
  InOrderVisit(root); cout << endl;
  InOrderVisitStack(root); cout << endl;
  InOrderVisitNoStack(root); cout << endl; 
  InOrderVisitMorris(root); cout << endl;
  cout << endl;

  SetVisited(root);
  cout << "PostOrderVisit:" << endl;
  PostOrderVisit(root); cout << endl;
  PostOrderVisitStack(root); cout << endl;
  PostOrderVisitNoStack(root); cout << endl;
  PostOrderVisitMorris(root); cout << endl;

  DestroyTree(root);
  return 0;
}
