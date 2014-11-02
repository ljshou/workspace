/**
 * @file lazy.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-26
 */

#include <iostream>
using namespace std;

class Singleton
{
public:
  static Singleton* getInstance() {
    if(data_ == nullptr) {
      cout << "object newed" << endl;
      data_ = new Singleton();
    }
    return data_;
  }
  void destructor() {
    if(data_ != nullptr) {
      delete data_;
      data_ = nullptr;
    }
  }
private:
  Singleton() {}
  int integer;
  static Singleton *data_;
};

Singleton* Singleton::data_ = nullptr;

int main(void)
{
  Singleton *p = Singleton::getInstance();
  p->destructor();
  return 0;
}
