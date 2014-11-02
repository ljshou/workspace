/**
 * @file ternary-tree.cc
 * @brief ternary tree
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-22
 */

#include "ternary-tree.h"
using namespace std;

int main(void)
{
  TernaryTree tree;
  string s;

  tree.Input(string("dict.dat"));

  cout << "Please input a string: " << endl;
  cin >> s;
  tree.Dfs(s);

  return 0;
}

