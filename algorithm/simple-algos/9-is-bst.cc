// copyright @ L.J.SHOU Feb.25, 2014
// test whether a vector is post-traversal result of BST
#include <iostream>
#include <vector>
using namespace std;

bool IsBST(vector<int>::iterator begin, vector<int>::iterator end)
{
  if (end - begin < 3)
    return true;
  
  //左子树 小于当前节点，小于右子树
  vector<int>::iterator left_end = begin;
  for(; *left_end <= *(end-1); ++ left_end); //use root as sentinel
  for(vector<int>::iterator it = left_end+1; it != end; ++it)
    if (*it < *(end-1))
	  return false;

  //left tree is a BST, and right tree as well
  if (IsBST(begin, left_end) && IsBST(left_end, end-1))
    return true;
  else
    return false;
}

int main(void)
{
  vector<int> a;
  a.push_back(5);
  a.push_back(7);
  a.push_back(6);
  a.push_back(9);
  a.push_back(1);
  a.push_back(10);
  a.push_back(8);

  cout << IsBST(a.begin(), a.end()) << endl;
  return 0;
}
