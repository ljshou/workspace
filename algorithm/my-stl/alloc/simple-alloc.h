// Last Update:2014-05-04 15:48:22
/**
 * @file simple-alloc.h
 * @brief a simple allocator
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-04
 */

#ifndef SIMPLE-ALLOC_H
#define SIMPLE-ALLOC_H

const size_t MaxMemorySize =  1<<20;

class MyAlloc
{
public:
  MyAlloc();
  ~MyAlloc();

  void* Allocate(size_t bytes);
private:
  char* begin;
  char* cur;
  char* end;
  //copying not allowed
  MyAlloc(const MyAlloc&);
  MyAlloc& operator=(const MyAlloc&);
};

MyAlloc::MyAlloc()
{
  cur = begin = new char[MaxMemorySize];
  end = begin + MaxMemorySize;
}

MyAlloc::~MyAlloc()
{
  delete [] begin;
}

void* MyAlloc::Allocate(size_t bytes)
{
  char* result = cur;
  cur += bytes;
}

#endif  /*SIMPLE-ALLOC_H*/
