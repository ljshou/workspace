/**
 * @file simple_string.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-06
 */
#include "ref_string.h"

int main(void)
{
  String str1;
  cout << str1 << endl;
  String str2("hello world");
  cout << "size: " << str2.size() << endl;
  cout << str2 << endl;
  str1 = str2;
  cout << str1 << endl;
  str1[1] = 'a';
  cout << str1 << endl;

  return 0;
}
