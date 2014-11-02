/**
 * @file my-int.cc
 * @brief a simple class
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-30
 */

#include <iostream>
using namespace std;

class MyINT{
public:
  MyINT(int x=0): i(x){}

  operator int() const{
    return i;
  }
private:
  int i;
};

void print(int i)
{
  cout << "int" << endl;
}

void print(double i)
{
  cout << "double" << endl;
}
int main(void)
{
  MyINT x(1);
  cout << static_cast<int>(x) << endl;
  cout << static_cast<double>(x) << endl;

  print(static_cast<double>(x));

  return 0;
}

