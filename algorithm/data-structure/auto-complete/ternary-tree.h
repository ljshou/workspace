// Last Update:2014-04-29 22:47:20
/**
 * @file ternary-tree.h
 * @brief ternary tree
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-22
 */

#ifndef TERNARY-TREE_H
#define TERNARY-TREE_H

#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::endl;

struct Node
{
  char data;
  Node *left, *center, *right;
  bool isStr;
  Node(char x, bool flag)
    : data(x), left(NULL), right(NULL), center(NULL), isStr(flag) {}
};

class TernaryTree
{
public:
  TernaryTree(): root(NULL){}
  ~TernaryTree() { destroy_tree(root); 
    cout << "count: " << count << endl;}
  void Add(const string &str);
  bool Search(const string &str) const;
  // 打印所以以str开头的单词
  void Dfs(const string &str); 
  void Input(const string &file);

private:
  //not copyable
  TernaryTree(const TernaryTree &);
  TernaryTree& operator=(const TernaryTree&);
  Node *root;
  static size_t count;

  void add(const string &str, size_t pos, Node* &root);
  bool search(const string &str, size_t pos, Node *root) const;
  void dfs(Node *p, string &path); 
  void destroy_tree(Node* &root);
};

size_t TernaryTree::count = 0;

void TernaryTree::Add(const string &str)
{
  add(str, 0, root);
}

bool TernaryTree::Search(const string &str) const
{
  return search(str, 0, root);
}

void TernaryTree::add(const string &str, size_t pos, Node* &root)
{
  if(root == NULL){
    root = new Node(str[pos], false);
    ++ count;
  }

  if(str[pos] < root->data){
    add(str, pos, root->left);
  }
  else if(str[pos] > root->data){
    add(str, pos, root->right);
  }
  else{
    if(pos + 1 == str.size()){
      root->isStr = true;
      return;
    }
    add(str, pos+1, root->center); 
  }
}

bool TernaryTree::search(const string &str, size_t pos, Node *root) const
{
  if(str.empty() || root == NULL) return false;

  if(str[pos] < root->data){
    return search(str, pos, root->left);
  }
  else if(str[pos] > root->data){
    return search(str, pos, root->right);
  }
  else{
    if(pos + 1 == str.size())
      return root->isStr;
    return search(str, pos+1, root->center);
  }
}

void TernaryTree::Dfs(const string &str)
{
  Node *p(root);
  int cur(0);

  while(p && cur != str.size())
  {
    if(p->data == str[cur]){
      p = p->center;
      ++ cur;
    }
    else if(p->data > str[cur]){
      p = p->left;
    }
    else{
      p = p->right;
    }
  }

  string path = str;
  // find the root node 
  dfs(p, path);
}

void TernaryTree::dfs(Node *p, string &path) 
{
  if(p == NULL) return;
  
  // center sub-tree
  path.push_back(p->data);
  if(p->isStr) cout << path << endl;
  dfs(p->center, path);
  path.resize(path.size()-1);

  // left sub-tree
  dfs(p->left, path);
  
  // right sub-tree
  dfs(p->right, path);
}

void TernaryTree::destroy_tree(Node* &root)
{
  if(root == NULL) return;
  destroy_tree(root->left);
  destroy_tree(root->center);
  destroy_tree(root->right);

  delete root;
  root = NULL;
}

void TernaryTree::Input(const string &str)
{
  std::ifstream ifile(str.c_str());

  string word;

  while(ifile >> word)
  {
    Add(word);
  }

  ifile.close();
}

#endif  /*TERNARY-TREE_H*/
