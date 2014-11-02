/**
 * @file pointer-container.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-17
 */

#include <bits/stdc++.h>
using namespace std;

struct DeleteObject {
  template<class T>
  void operator()(const T* ptr) {
    delete ptr;
  }
};

int main(void)
{
  vector<int*> vec;
  for(int i=0; i<10; ++i)
  {
    vec.push_back(new int(i));
  }
  //for_each(vec.begin(), vec.end(), DeleteObject());
  
  //lambda
  for_each(vec.begin(), vec.end(), [] (const int* p) {
    delete p;
  });

  vector<shared_ptr<int>> vec2;
  for(int i=0; i<10; ++i)
  {
    vec2.push_back(make_shared<int>(i));
  }

  return 0;
}
