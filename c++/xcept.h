#ifndef NoMem_
#define NoMem_

#include<iostream>
using namespace std;
// 内存不足
class NoMem {
public:
	NoMem () {}
};
// 使new引发NoMem异常而不是 xalloc异常

void my_new_handler()
{
	throw NoMem();
}
new_handler Old_Handler_=set_new_handler(my_new_handler);

class OutOfBounds
{
public:
	OutOfBounds() {
	cout<<" Out of bounds!!!"<<endl; }
};

class BadInitializers
{
public:
  BadInitializers(){
    cout << " Bad initializers!!!" << endl;
  }
};

class SizeMismatch
{
public:
  SizeMismatch(){
    cout << " Size mismatched!!!" << endl;
  }
};

#endif
