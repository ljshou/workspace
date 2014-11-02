#include "stack.h"
#include <iostream>
using namespace std;

int main(void)
{
  SHOU::Stack s;
  for(int i=0; i<10; ++i)
    s.push(i);
  cout << "top: " << s.top() << endl;
  for(int i=0; i<10; ++i)
    cout << s.pop() << endl;

  return 0;
}
