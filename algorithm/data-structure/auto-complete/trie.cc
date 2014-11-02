/**
 * @file trie.cc
 * @brief trie 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-16
 */
#include "trie.h"
#include <iostream>
using namespace std;

int main(void)
{
  Trie trie;
  string str;

  // input dictionary
  trie.Input(string("dict.dat"));

  // testing AutoComplete
  cout << "please input a string: " << endl;
  cin >> str;
  trie.AutoComplete(str);

  return 0;
}

