// copyright @ L.J.SHOU Mar.04, 2014
// do not use + - * /, if, while to compute
// 1+2+...+n

#include <iostream>
#include <ctime>
using namespace std;

// Method 1: TMP, reference: Effective C++
template<unsigned n>
struct MySum{
  enum { value = MySum<n-1>::value + n };
};

// use template specialization to mimic if expression
template<>
struct MySum<0>{
  enum { value = 0 };
};

// Method 2: recursive function
int Sum(int n)
{
  int ret = 0;
  n == 0 || (ret = Sum(n-1));
  return n + ret;
}

// Method 3: static variable of class
struct MyClass{
  MyClass(){
    sum += ++ n;
  }
  static int n; 
  static int sum;
};
int MyClass::n = 0;
int MyClass::sum = 0;


int main(void)
{
  cout << MySum<10>::value << endl;

  cout << Sum(10) << endl;

  MyClass a[10];
  cout << MyClass::sum << endl;

  return 0;
}
