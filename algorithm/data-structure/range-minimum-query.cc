/**
 * @file rmq.cc
 * @brief  RMQ
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-10
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
  int val;
  Node *left, *right;
  Node(int x=0): val(x), left(NULL), right(NULL) {}
};

/**
 * recursive version
 * build a RMQ tree
 * */
Node* BuildTree(int *a, int left, int right)
{
  //EXIT
  if(left > right) return NULL;

  Node *root(NULL);
  int min_index = min_element(a+left, a+right+1) - a;
  root = new Node(a[min_index]);
  root->left = BuildTree(a, left, min_index - 1);
  root->right = BuildTree(a, min_index+1, right);

  return root;
}

/**
 * O(n) version
 * build a RMQ tree
 */
Node* BuildTree2(int *a, int left, int right)
{
  Node *root(NULL), *cur(NULL), *pre(NULL);
  Node *node(NULL);
  for(int i=left; i<=right; ++i)
  {
    //like inserting into a sorted list
    pre = NULL; cur = root;
    while(cur && cur->val < a[i]){
      pre = cur;
      cur = cur->right;
    }
    node = new Node(a[i]);
    node->left = cur;
    if(pre == NULL){
      root = node;
    }
    else{
      pre->right = node;
    }
  }
  return root;
}

Node* DestroyTree(Node *root)
{ //EXIT
  if(root == NULL) return NULL;
  root->left = DestroyTree(root->left);
  root->right = DestroyTree(root->right);
  delete root;
  return NULL;
}

void InOrder(Node *root) 
{
  //Exit
  if(root == NULL) return;
  InOrder(root->left);
  cout << root->val << " ";
  InOrder(root->right);
}

int main(void)
{
  int a[] = {3, 1, 5, 6, 0, 7};
  Node *root = BuildTree2(a, 0, sizeof(a)/sizeof(int)-1);
  InOrder(root);
  
  root = DestroyTree(root);
  return 0;
}
