// Last Update:2014-03-23 17:01:44
/**
 * @file handle.h
 * @brief handle class
 *        another smart pointer class
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-19
 */

#ifndef HANDLE_H
#define HANDLE_H

#include "item.h"
#include <iostream>

class Handle{
public:
  Handle()
  :p(NULL), use(new std::size_t(1)) { }

  ~Handle() {
      decr_use();
  }
  Handle(const Item_base&);

  // copy control
  Handle(const Handle &rhs)
  :p(rhs.p), use(rhs.use){
    ++ *use;
  }
  Handle& operator=(const Handle &rhs){
    ++ *(rhs.use);
    decr_use();
    
    use = rhs.use;
    p = rhs.p;
    return *this;
  }

  Item_base& operator*(){
    return *p;
  }
  const Item_base& operator*() const{
      return *p;
  }
  Item_base* operator->(){
    return p;
  }
  const Item_base* operator->() const{
      return p;
  }

private:
  Item_base *p;
  std::size_t *use;
  // called by both destructor and assignment operator to free pointers
  void decr_use(){
      if( -- *use == 0){
        delete p;
        delete use;
      }
  }
};

Hanlde::Handle(const Item_base& item)
: p(item.clone()), use(new std::size_t(1))
{
}



#endif  /*HANDLE_H*/
