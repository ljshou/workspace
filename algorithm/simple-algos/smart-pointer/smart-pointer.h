// copyright @ L.J.SHOU Dec.23, 2013
// smart pointer using counting reference

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include <cassert>
#include <iostream>
namespace SHOU{

// private class for SmartPointer
class Ptr{
  friend class SmartPointer;
private:
  int *p_;
  std::size_t use_; // referece count

  Ptr(int *p): p_(p), use_(1) {}
  ~Ptr() { delete p_; }
};

class SmartPointer{
public:
  SmartPointer(int *p): ptr_(new Ptr(p)) {} 
  SmartPointer(const SmartPointer &rhs):
    ptr_(rhs.ptr_) { ++ ptr_->use_; }
  SmartPointer& operator=(const SmartPointer &rhs); 
  ~SmartPointer() { 
    --ptr_->use_; 
	if(ptr_->use_ < 1) delete ptr_; 
  }

  //member access function
  int& operator*()const { assert(ptr_); return *ptr_->p_; }
private:
  Ptr *ptr_;
};

// copy assignment 
// self-assigning is also allowed
SmartPointer& SmartPointer::operator=(const SmartPointer &rhs)
{
  ++ rhs.ptr_->use_;// increment rhs object's counting number 
  -- ptr_->use_;
  if(ptr_->use_ < 1)
    delete ptr_;
  // assignment
  ptr_ = rhs.ptr_;
  return *this;
}

};//end of namespace SHOU
#endif
