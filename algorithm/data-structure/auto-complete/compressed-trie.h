// Last Update:2014-05-01 10:13:01
/**
 * @file compressed-trie.h
 * @brief a compressed trie
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-01
 */

#ifndef COMPRESSED-TRIE_H
#define COMPRESSED-TRIE_H

struct Node
{
  char data;
  Node *center, *right;
  bool isStr;
  Node(char x, bool flag)
    : data(x), center(NULL), right(NULL), isStr(flag) {}
};

class CompressedTrie
{
public:
  CompressedTrie() :root(NULL) {}
  ~CompressedTrie(){ destroy_tree(root); }
private:
};


#endif  /*COMPRESSED-TRIE_H*/
