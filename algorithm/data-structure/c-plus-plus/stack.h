// copyright @ L.J.SHOU Dec.23, 2013
// stack
#include <iostream>
namespace SHOU{

struct Node
{
  int val;
  struct Node *next;
  Node(int x=-1, struct Node *p=NULL):
    val(x), next(p) {}
};
typedef struct Node StackNode;

class Stack
{
public:
  Stack(StackNode *s=NULL): top_(s){}
  ~Stack(){
    StackNode *next(NULL);
	while(top_)
	{
	  next = top_->next;
	  delete top_;
	  top_ = next;
	}
  }
  int pop();
  void push(int x);
  int top();
private:
  StackNode *top_; 
};

// assume all nodes are positive
// if stack is empty, return -1
int Stack::pop()
{
  StackNode *node(NULL);
  if(top_ != NULL)
  {
    int x = top_->val;
	node = top_;
	top_ = top_->next;
	delete node;
	return x;
  }
  return -1;
}

void Stack::push(int x)
{
  StackNode *node(NULL);
  node = new StackNode(x, top_);
  top_ = node;
}

int Stack::top()
{
  if(top_ != NULL)
    return top_->val;
  else
    return -1;
}
};
