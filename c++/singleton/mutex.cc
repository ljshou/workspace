/**
 * @file mutex.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-26
 */
#include <iostream>
using namespace std;

class Singleton
{
public:
  static Singleton* getInstance() {
    if(data_ == NULL) {
      lock();
      if(data_ == NULL) {
        data_ = new Singleton();
      }
      unlock();
    }
    return data_;
  }
private:
  static Singleton *data_;
};
