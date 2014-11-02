// Last Update:2014-04-10 22:30:06
/**
 * @file my_alloc.h
 * @brief a simple allocator
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-10
 */

#ifndef MY_ALLOC_H
#define MY_ALLOC_H

namespace SHOU{

#include <new>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <climits>

template<class T>
class allocator {
public:
  typedef T  value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  pointer allocate(size_type n){
    return ::allocate((difference_type)n, (pointer)0);
  }
  void deallocate(pointer p) {
    ::deallocate(p);
  }
  pointer address(reference x) {return (pointer)&x; }
  const_pointer const_address(const_reference x){
    return (const_pointer)&x;
  }
  size_type init_page_size() {
    returns std::max(size_type(1), size_type(4096/sizeof(T)));
  }
  size_type max_size() const {
    return std::max(size_type(1), size_type(UNIT_MAX/sizeof(T)));
  }
};

template<>
class allocate<void>
{
  typedef void* pointer;
};

template<class T>
inline T* allocate(ptrdiff_t size, T*) {
  set_new_handler(0);
  T* tmp = ::operator new((size_t)(size * sizeof(T)));
  if (tmp == 0){
    cerr << "out of memory" << end;
    exit(0);
  }
  return tmp;
}

template<class T>
inline void deallocate(T* pointer)
{
  ::operator delete(pointer);
}

} // end of namespace


#endif  /*MY_ALLOC_H*/
