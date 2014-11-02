/**
 * @file valid-ip.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-08-31
 */

#include <bits/stdc++.h>
using namespace std;

// 127.01.0.0 认为无效
bool Valid(const string &str) {
  for(auto x : str) 
    if(!(x >= '0' && x <= '9')) 
      return false;
  int num = atoi(str.c_str());
  if(num < 0 || num > 255) return false;
  if(str.size() > 1 && str[0] == '0') return false;
  return true;
}

bool IsValidIp(const string &str)
{
  const int n = str.size();
  if(n < 7 || n > 15) return false;
  int start(0), end(0), count(0);
  end = str.find_first_of(".");
  while(end != string::npos && count < 4) {
    if(end == start || end-start>3) return false;
    if(!Valid(str.substr(start, end-start))) return false;

    ++ count;
    start = end+1;
    end = str.find_first_of(".", start);
  }
  if(count != 3) return false;
  if(end == string::npos) {
    if(end == start || end-start>3) return false;
    if(!Valid(str.substr(start, end-start))) return false;
  }

  return true;
}


int main(void)
{
  cout << IsValidIp("127.01.0.0") << endl;
  return 0;
}
