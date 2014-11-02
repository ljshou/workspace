/**
 * @file queue.cc
 * @brief queue using two stacks
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-10
 */
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
  void push(int x);
  void pop();
  int top();
private:
  stack<int> a, b;
};

void MyQueue::push(int x)
{
  a.push(x);
}

void MyQueue::pop()
{
  if(b.empty())
  {
    while(!a.empty())
    {
      b.push(a.top());
      a.pop();
    }
  }
  if(!b.empty())
    b.pop();
}

int MyQueue::top() 
{
  if(b.empty())
  {
    while(!a.empty())
    {
      b.push(a.top());
      a.pop();
    }
  }
  if(!b.empty())
    return b.top();
  else
    cerr << "empty" << endl;
}

int main(void)
{
  MyQueue que;
  que.push(1);
  que.push(2);
  que.push(3);
  cout << que.top() << endl;
  que.pop();
  cout << que.top() << endl;
  que.pop();
  cout << que.top() << endl;
  que.pop();

  return 0;
}


