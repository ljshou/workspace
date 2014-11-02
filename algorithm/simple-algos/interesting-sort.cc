/**
 * @file interesting-sort.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-13
 */
#include <iostream>
#include <algorithm>
using namespace std;

class compare{
public:
  bool operator()(char lhs, char rhs){
    if(lhs >= 'a' && lhs <= 'z' &&
       rhs >= '0' && rhs <= '9')
      return true;
    else if(lhs >= '0' && lhs <= '9' &&
       rhs >= 'a' && rhs <= 'z')
      return false;
    else
      return lhs < rhs;
  }
};
int main(void)
{
  string str("082a34c6b5c7");

  sort(str.begin(), str.end(), compare());
  cout << str << endl;

  return 0;
}

