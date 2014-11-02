// Last Update:2014-04-16 23:24:47
/**
 * @file trie.h
 * @brief Trie
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-16
 */

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using std::string;
using std::cout;
using std::endl;

const int branchNum = 26; 

struct TrieNode
{
  TrieNode(): isStr(false)
  {
    memset(next, 0, sizeof(next));
  }
  bool isStr;
  TrieNode* next[branchNum];
};

string ToLower(const string &s)
{
  string str;
  string::const_iterator it = s.begin();
  while(it != s.end())
  {
    str += (char)tolower(*it);
    ++ it;
  }
  return str;
}

/**
 * a simple data stucture
 * usefull for AutoComplete
 */
class Trie
{
public:
  Trie(): root(new TrieNode()) {}
  ~Trie() { 
    cout << "# of nodes allocated: " << count << endl;
    destroy(root); }
  
  void Insert(const string &str);
  bool Search(const string &str) const;
  void AutoComplete(const string &str);
  void Input(const string &file);

private:
  TrieNode* find(const string &str) const;
  void dfs(TrieNode *root, string &path);
  void destroy(TrieNode * &root);

  TrieNode *root;
  static size_t count;
};

size_t Trie::count = 0;

void Trie::destroy(TrieNode * &root)
{
  for(int i=0; i<branchNum; ++i)
  {
    if(root->next[i])
      destroy(root->next[i]);
  }
  delete root;
  root = NULL;
}

void Trie::Insert(const string &s)
{
  if(s.empty()) return;

  /* support lower cases now */
  string str = ToLower(s);
  string::const_iterator it = str.begin();
  TrieNode *location(root);

  // bypassing existing nodes
  while(it != str.end() && location->next[*it - 'a'] != NULL)
  {
    location = location->next[*it - 'a'];
    ++ it;
  }

  // Insert
  while(it != str.end() && location->next[*it - 'a'] == NULL)
  {
    location->next[*it - 'a'] = new TrieNode();
    ++ count;
    location = location->next[*it - 'a'];
    ++ it;
  }
  location->isStr = true;
}

void Trie::Input(const string &str)
{
  std::ifstream ifile(str.c_str());

  string word;

  while(ifile >> word)
  {
    Insert(word);
  }

  ifile.close();
}

bool Trie::Search(const string &s) const
{
  TrieNode *location = root;

  string str = ToLower(s);
  location = find(str); 
  return (location) && location->isStr;
}

TrieNode* Trie::find(const string &str) const
{
  TrieNode *location = root;
  string::const_iterator it = str.begin();
  while(it != str.end() && location->next[*it - 'a'] != NULL)
  {
    location = location->next[*it - 'a'];
    ++ it;
  }
  return (it == str.end()) ? location : NULL;
}

void Trie::dfs(TrieNode *root, string &path)
{
  if(root == NULL) return;

  if(root->isStr) 
    cout << path << endl;
  for(char x='a'; x<='z'; ++x)
  {
    if(root->next[x-'a'] != NULL)
    {
      path += x;
      dfs(root->next[x-'a'], path);
      path.resize(path.size()-1);
    }
  }
}

void Trie::AutoComplete(const string &str) 
{ 
  TrieNode *location(root);
  string path;

  location = find(str);
  path = str;
  dfs(location, path);
}

#endif  /*TRIE_H*/
