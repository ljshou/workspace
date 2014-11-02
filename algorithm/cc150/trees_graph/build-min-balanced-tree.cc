/**
 * @file build-min-balanced-tree.cc
 * @brief Given a sorted(increasing) order array, write an algo. to create
 * a binary tree with minimal height.
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-08-12
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node(int x=0):val(x), left(nullptr), right(nullptr) {}
};

Node* addToTree(int *a, int left, int right) {
  assert(a != nullptr);
  if(left > right) return nullptr;
  Node *root(nullptr);
  int mid = left + (right - left)/2;
  root = new Node(a[mid]);
  root->left = addToTree(a, left, mid-1);
  root->right = addToTree(a, mid+1, right);
  return root;
}

void InOrder(Node *root) 
{
  if(root == nullptr) return;
  InOrder(root->left);
  cout << root->val << " ";
  InOrder(root->right);
}

Node* DestroyTree(Node *root) {
  if(root == nullptr) return nullptr;
  root->left = DestroyTree(root->left);
  root->right = DestroyTree(root->right);
  delete root;
  return nullptr;
}

int main(void)
{
  int a[] = {1,2,3,4};
  Node *root = addToTree(a, 0, sizeof(a)/sizeof(int) - 1);
  InOrder(root);
  cout << endl;
  root = DestroyTree(root);
  return 0;
}
