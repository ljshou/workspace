/**
 * @file substitute.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-11
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  string str, word, target;
  string res;
  getline(cin, str);
  getline(cin, word);
  getline(cin, target);

  int pre = 0;
  int cur = str.find(word);
  while(cur != string::npos) {
    if(cur > 0 && str[cur-1] != ' ')
    {
      cur += word.size();
      res += string(str, pre, cur-pre);
    }
    else
    {
      res += string(str, pre, cur-pre) + target;
      cur += word.size();
    }
    pre = cur;
    cur = str.find(word, cur);
  }
  res += string(str.begin()+pre, str.end());
  cout << res << endl;
  return 0;
}
