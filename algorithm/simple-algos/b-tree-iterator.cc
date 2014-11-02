/**
 * @file b-tree-iterator.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-07
 */
#include "data-structure/binary-build-tree.h"
#include <bits/stdc++.h>
using namespace std;

class Iterator {
public:
  virtual TreeNode* next() = 0;
};

class PreOrderIterator : public Iterator {
public:
  PreOrderIterator(TreeNode * root) {
    if(root) s.push(root);
  }

  virtual TreeNode* next() {
    TreeNode *top(nullptr);
    if(!s.empty()) {
      top = s.top();
      s.pop();

      if(top->right_child) 
        s.push(top->right_child);

      if(top->left_child) 
        s.push(top->left_child);
    }
    return top;
  }

private:
  stack<TreeNode*> s;
};

class InOrderIterator : public Iterator {
public:
  InOrderIterator(TreeNode * root) {
    while(root) {
      s.push(root);
      root = root->left_child;
    }
  }

  virtual TreeNode* next() {
    TreeNode *top(nullptr);
    TreeNode *cur(nullptr);
    if(!s.empty()) {
      top = cur = s.top();
      s.pop();
      cur = cur->right_child;
      while(cur) {
        s.push(cur);
        cur = cur->left_child;
      }
    }
    return top;
  }

private:
  stack<TreeNode*> s;
};

class PostOrderIterator : public Iterator {
public:
  PostOrderIterator(TreeNode *root): pre(nullptr) {
    while(root) {
      s.push(root);
      root = root->left_child;
    }
  }

  virtual TreeNode* next() {
    TreeNode *cur(nullptr);

    while(cur || !s.empty()) {
      while(cur) {
        s.push(cur);
        cur = cur->left_child;
      }
      cur = s.top(); s.pop(); 
      if(nullptr == cur->right_child || pre == cur->right_child) {
        //right_child is nullptr or already visited
        pre = cur;
        return cur;
      }
      else {
        s.push(cur);
        cur = cur->right_child;
      }
    }
    return nullptr;
  }

private:
  TreeNode *pre; //previously visited node
  stack<TreeNode*> s;
};

void PreOrderVisit(TreeNode * root)
{
  if(root)
  {
    cout << root->value << " ";
    PreOrderVisit(root->left_child);
    PreOrderVisit(root->right_child);
  }
}

void InOrderVisit(TreeNode * root)
{
  if(root)
  {
    InOrderVisit(root->left_child);
    cout << root->value << " ";
    InOrderVisit(root->right_child);
  }
}

void PostOrderVisit(TreeNode * root)
{
  if(root)
  {
    PostOrderVisit(root->left_child);
    PostOrderVisit(root->right_child);
    cout << root->value << " ";
  }
}

int main(void)
{
  TreeNode *root;
  string pre("ABDEGHJCFI"), in("DBGEHJACIF"); 
  CreateTree(root, pre, in);

  cout << "InOrderVisit: " << endl;
  PostOrderVisit(root); cout << endl;

  PostOrderIterator iter(root);
  TreeNode *node = iter.next();
  while(node) {
    cout << node->value << " ";
    node = iter.next();
  }
  cout << endl;

  DestroyTree(root);
  return 0;
}
