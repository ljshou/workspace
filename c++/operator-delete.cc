/**
 * @file operator-delete.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-22
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
  A() {}

  //void* operator new[](size_t n, const char* file, int line)
  void* operator new(size_t n, int line)
  {
    cout << " " << line << " : allocating array" << endl;
    //throw runtime_error("");
    return ::operator new(n);
  }
  //void operator delete[](void *ptr, const char* file, int line) {
  void operator delete(void *ptr, int line) {
    cout << " " << line << " : deleting array" << endl;
    ::operator delete(ptr);
  }
};

int main(void)
{
  //A *p = new (__FILE__, __LINE__)A[5];
  A *p = new (__LINE__)A();
  delete p;//(__FILE__, __LINE__);
  return 0;
}
