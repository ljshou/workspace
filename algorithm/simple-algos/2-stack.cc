// copyright @ L.J.SHOU Feb.17, 2014
// design a stack
// min, push, pop take O(1) time
#include <iostream>
using namespace std;

/* 无穷大 */
const int INT = 0xfffff;

template<typename T>
class MyStack{
public:
  MyStack(int capacity=100)
    :capacity_(capacity), top_(-1){
	  stack_ = new T[capacity_]; 
	  min_   = new T[capacity_]; 
	}

  ~MyStack(){ 
    delete [] stack_; 
    delete [] min_; 
  }

  void push(const T& t){
    if(top_ < capacity_){
	  stack_[top_ + 1] = t;

	  if(top_ < 0 || min_[top_] > t){
	    min_[top_ + 1] = t;
	  }
	  else{
	    min_[top_ + 1] = min_[top_];
	  }

	  ++ top_;
	}
	else{
	  cerr << "stack is full" << endl;
	}
  }

  void pop(void){
    if(top_ >= 0){
	  -- top_;
	}
	else{
	  cerr << "stack is empty" << endl;
	}
  }

  T top(){
    if(top_ >= 0){
	  return stack_[top_];
	}
	else{
	  cerr << "stack is empty" << endl;
	  return INT;
	}
  }

  T min(){
    if(top_< 0){ 
	  cerr << "stack is empty" << endl;
	  return INT;
	}
    return min_[top_];
  }

private:
  int capacity_; //max_size
  int top_;    
  T *stack_;
  T *min_;
};

int main(void)
{
  MyStack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);

  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.min() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;

  return 0;
}
