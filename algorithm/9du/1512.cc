/**
 * @file 1512.cc
 * @brief two stack to mimic queue
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-29
 */
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class CQueue
{
public:
  CQueue(void) {}
  ~CQueue(void) {}

  void appendTail(const T& node);
  T deleteHead();

private:
  stack<T> stack1;
  stack<T> stack2;
};

template<typename T>
inline void CQueue<T>::appendTail(const T& node)
{
  stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
  if(stack2.empty()) {
    while(!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }
  }
  if(stack2.empty()) {
    return -1;
  }
  else {
    T res = stack2.top();
    stack2.pop();
    return res;
  }
}

int main(void)
{
  int n, num;
  char command[10];
  CQueue<int> q;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
  {
    scanf("%s", command);
    if(strncmp(command, "PUSH", 4) == 0) {
      scanf("%d", &num);
      q.appendTail(num);
    }
    else {
      printf("%d\n", q.deleteHead());
    }
  }
  return 0;
}
