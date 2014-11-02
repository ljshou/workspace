/**
 * @file final.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-26
 */
#include <bits/stdc++.h>
using namespace std;

class Singleton
{
public:
  static Singleton& getInstance() {
    cout << "getInstance() called" << endl;
    static Singleton theSingleton;
    return theSingleton;
  }
private:
  Singleton() {}
  Singleton(const Singleton &);
  void operator=(const Singleton&);
  ~Singleton() {}

  struct ProxyObject {
    ProxyObject() {
      cout << "ProxyObject constructed" << endl;
      Singleton::getInstance();
    }
  };
  static ProxyObject object;
};

Singleton::ProxyObject Singleton::object;

int main(void)
{
  cout << "entering main" << endl;
  return 0;
}
