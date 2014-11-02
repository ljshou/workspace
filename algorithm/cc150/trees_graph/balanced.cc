/**
 * @file balanced.cc
 * @brief check whether a binary tree is balanced
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-08-12
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node(int x=0): val(x), left(nullptr), right(nullptr) {}
};

bool Helper(Node *root, int &depth) {
  if(root == nullptr) {
    depth = 0;
    return true;
  }
  int leftDepth(0), rightDepth(0);
  bool flag(true);
  flag = Helper(root->left, leftDepth) && Helper(root->right, rightDepth);
  depth = max(leftDepth, rightDepth) + 1;
  return flag && abs(leftDepth - rightDepth) <= 1;
}

bool IsBalanced(Node *root) {
  int depth(0);
  return Helper(root, depth);
}

int main(void)
{
  Node *root(nullptr);
  Node node[5] = {0,1,2,3,4};
  node[0].left = &node[1];
  node[1].right = &node[2];
  node[0].right = &node[3];
  root = &node[0];

  cout << IsBalanced(root) << endl;
  return 0;
}
