#include<iostream>
#include<string>
using namespace std;

class A
{
public:
  virtual void print() { cout << "print A:" << endl;}

private:
  int a;
};

class B : public A
{
public:
  virtual void print() { cout << "print B:" << endl;}
  void output() {}
};

typedef void (*pFunc)();

int main()
{
  A* pBase = new B;
  pBase->print();
  cout << "sizeof A: " << sizeof(A) << endl;
  cout << "sizeof B: " << sizeof(B) << endl;
  
  //cout << *(dynamic_cast<B*>(pBase)->p) << endl;
  dynamic_cast<B*>(pBase)->output();

  A a;
  cout << "vptr of Base " << *(int*)&a << endl;

  B d[2];
  cout << "vptr of d[0] " << *(int*)&d[0] << endl;
  cout << "vptr of d[1] " << *(int*)&d[1] << endl;

  pFunc p;
  p = (pFunc)(*(int*)(*(int*)&d[0]));
  p();
  delete pBase;
  return 0;
}
