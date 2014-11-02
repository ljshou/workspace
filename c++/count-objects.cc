/**
 * @file count-objects.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-05
 */
#include <bits/stdc++.h>
using namespace std;

//Version 1 : counting objects of a class
class A
{
private:
  static int count;
public:
  A(){++count;}
  A(const A&){++count;}
  ~A(){--count;}
  static int howMany(){return count;}
};
int A::count = 0; //the static keyword must be ignored when defined




//Version 2: define a class which is only used to count the number of objects of a class
//By the relationship of new expressions and operator delete, we automake the counting of class instantiate
//
//define a class used to count the class instantiates for other classes(so it is need to be a template class)
template<class T>
class Counter
{
private:
  static size_t count;
  //void operator delete(void *);
  
public:
  Counter(){++count;};
  Counter(const Counter &){++count;}
  ~Counter(){--count;}
  static size_t howMany(){return count;}
};
template<class T>
size_t Counter<T>::count = 0;

//将Counter直接作为data member 同样是会增加对象的大小，这显然也不是我们期望的.
class Widget
{
private:
  int x;
  Counter<Widget> c; //as a data member,is implemented as...
public:
  static const size_t howMany()
  {
    return Counter<Widget>::howMany();
  }
};

//pubic Inherient
//but the method require the base dtor is virtual!!
//显然这是不合理的，类Widget2只是利用Counter来计数，就导致该类的对象size变大（因为vptr）
//可以禁止“通过基类的指针来delete派生类的对象，于是乎将基类的operator delete声明为私有的”
//但是很奇怪的是，将operator delete声明为私有的之后，new操作符也不能成功的调用了.
//我自己认为是如果new成功了的话，最后却不能调用operator delete这显然会造成内存泄露，于是乎编译器本着早报告错误的原则，直接使得new不通过编译
class Widget2:public Counter<Widget2>
{
private:
  int x;
public:
  static const size_t howMany()
  {
    return Counter<Widget2>::howMany();
  }
};

//于是乎，经过尝试之后，我们陷入了困境。

//考虑上述的继承，我们要禁止的是通过基类的指针去释放派生类，但是我们的行为（将opearator delete声明为private）却使得我们连new都不行了（这其实是很合理的）。那么我们干脆就直接禁止基类的指针指向派生类的成员，于是乎 private 继承！！！
//Version 3: private Inherient
class Widget3:private Counter<Widget3>
{
private:
  int x;
public:
  // using Counter<Widget3>::howMany;
  static const size_t howMany()
  {
    return Counter<Widget3>::howMany();
  }
};

int main()
{
  Widget3 a,b,c;
  Widget3 d = a;
  Widget3 e(b);
  Widget3 *p = new Widget3();
  delete p;
  cout << Widget3::howMany() << endl;
  return 0;
}
