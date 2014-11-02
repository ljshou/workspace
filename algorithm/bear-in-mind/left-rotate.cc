// copyright @ L.J.SHOU Dec.19, 2013
// left-rotate in O(N) 
// type num: 1

#include <string>
#include <iostream>
using namespace std;

void ReverseString(string &str, int left, int right)
{
  if(left >= right) return;
  while(left < right)
  {
    swap(str[left++], str[right--]);
  }
}

bool LeftRotate(string &str, int n)
{
  if(n < 0) return false;
  int left(0), left_end(0), right(0), right_end(str.size()-1);

  n %= str.size();
  left_end = n-1;
  right = n;
  ReverseString(str, left, left_end);
  ReverseString(str, right, right_end);
  ReverseString(str, left, right_end);

  return true;
}

int main(void)
{
  string str("123abcd");

  if(LeftRotate(str, 3) != true)
    cout << "left rotate failed" << endl;

  for(int i=0; i<str.size(); ++i)
    cout << str[i] << " ";
  cout << endl;

  return 0;
}

