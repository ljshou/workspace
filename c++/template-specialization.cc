//usage of template specialization
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
int count(vector<T> t)
{
  return t.size();
}

int count(string str)
{
  return str.length();
}

int main(void)
{
  vector<int> vec;

  for(int i=0; i<10; ++i)
    vec.push_back(i);
  cout << count(vec) << endl;

  string str("abcdef");
  cout << count(str) << endl;

  return 0;
}
