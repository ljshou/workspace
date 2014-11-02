/**
 * @file  vector-destroy.cc
 * @brief an interesting problem regarding vector 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-16
 */

#include <iostream>
#include <vector>
using namespace std;

class MyClass
{
public:
  MyClass(int x=0)
   : val(x) {}

  ~MyClass() { 
    cout << val << " ";
  }
  void set_val(int x){
    val = x;
  }
private:
  int val;
};

int main(void)
{
  vector<MyClass> vec(5);

  for(vector<MyClass>::size_type i=0; i!=vec.size(); ++i)
    vec[i].set_val(i);

  // result is 0 0 1 2 3 4 
  // why two 0s ???

  return 0;
}
