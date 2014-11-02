//copyrigt @ L.J.SHOU May.25, 2014
#include <bits/stdc++.h>
using namespace std;

/**
 * This class is a functional datatype, representing 
 *      an immutable stack of objects.
 *
 * 1. stack is based on a list implementation
 * 2. std::shared_ptr is used to collect garbage
 * 3. thread safe
 */

template<class T>
struct Node {
  Node(T x, shared_ptr<Node > &tail) 
    : val_(x), next_(tail), max_(x){
      if(tail) max_ = max(val_, tail->max_); 
    }

  /** 
   * To avoid too deep recursive call
   *
   * Normally, default destructor provided by c++ compiler is enough
   * but in some cases, where the list is too long,
   * the recursive call of this function would be too deep,
   * leading a stack overflow error.
   */
  ~Node() {
    shared_ptr<Node > *ptr = &next_, *next(nullptr);
    vector<shared_ptr<Node > > vec;

    while(*ptr) {
      if((*ptr).unique() == false) break;
      next = &((*ptr)->next_);
      vec.push_back(*ptr);
      *ptr = nullptr;
      ptr = next;
    }
  }
  T val_;
  T max_;
  shared_ptr<Node > next_;
};


template<typename T>
class Stack
{
public:
  Stack(): count_(0), head_(nullptr) {}
  Stack(T x, Stack tail): head_(make_shared<Node<T>>(x, tail.head_)){
    count_ = 1 + tail.count_;
  }

  int size() { return count_;}

  bool empty() { return count_ == 0;}

  T getMax() { assert(!empty()); return head_->max_;}

  T getHead() { assert(!empty()); return head_->val_;}

  Stack getTail() { assert(!empty()); return Stack(head_->next_, count_-1);}

  Stack addHead(const T &x) {
    return Stack(x, *this);
  }

  Stack reverse() {
    Stack new_list;
    Stack it = *this; // make a "copy" first
    for(int i=0; i<size(); ++i) {
      new_list = new_list.addHead(it.getHead());
      it = it.getTail();
    }
    return new_list;
  }

private:
  explicit Stack(shared_ptr<Node<T> > tail, int count) 
    : head_(tail), count_(count) {}

  shared_ptr<Node<T> > head_;
  int count_;
};

int main(void)
{
  Stack<int> list;
  for(int i=0; i<10; ++i)
    list = list.addHead(i);

  //print
  Stack<int> temp = list;
  while(!temp.empty()) {
    cout << temp.getHead() << " ";
    temp = temp.getTail();
  }
  cout << endl;

  return 0;
}
