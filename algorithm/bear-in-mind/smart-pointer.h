// Last Update:2014-04-14 10:49:34
/**
 * @file smart-pointer.h
 * @brief Smart Pointer using reference counting
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-14
 */

#ifndef SMART-POINTER_H
#define SMART-POINTER_H
#include <iostream>

template<class T>
class SmartPointer
{
public:
  SmartPointer(T value)
    : ptr(new T(value)), ref_count(new size_t(1)) {}
  ~SmartPointer() { remove(); }

  //copy control
  SmartPointer(const SmartPointer &rhs);
  SmartPointer& operator=(const SmartPointer &rhs);

  T* get_ptr() {return ptr;}
  T get_ptr_val() {return *ptr;}
  T& operator*() {return *ptr;}
  const T& operator*()const {return *ptr;}
  T* operator->() {return ptr;}

private:
  T* ptr;
  size_t *ref_count;

protected:
  void remove(){
    if(--*ref_count == 0){
      delete ptr;
      delete ref_count;
      ptr = NULL;
      ref_count = NULL;
    }
  }
};

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer &rhs)
  :ref_count(rhs.ref_count), ptr(rhs.ptr)
{
  ++ *ref_count;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer &rhs)
{
  //deal with self-assignment
  ++ *(rhs.ref_count);
  remove();
  ptr = rhs.ptr;
  ref_count = rhs.ref_count;

  return *this;
}


#endif  /*SMART-POINTER_H*/
