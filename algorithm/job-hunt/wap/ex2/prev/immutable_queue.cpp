//copyrigt @ L.J.SHOU May.25, 2014
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <queue>
using std::vector;
using std::queue;
using std::range_error;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

/**
 * This class is a functional datatype, representing 
 *      an immutable first-in-first-out(FIFO) queue of objects.
 *
 * amortized O(1) cost
 *
 * implementation details:
 * 1. two lists are used as stacks to mimic queue
 *    front: for dequeue 
 *    rear:  for enqueue
 *    Once front is empty, rear are reversed and added to front
 *    so front is empty, if and only if rear is empty too.
 *
 * 2. std::shared_ptr is used to collect garbage
 */
template<typename T>
class immutable_queue
{
  class List;
public:
  immutable_queue();
  immutable_queue(List front, List rear);
  ~immutable_queue();
  immutable_queue<T> enqueue(const T &element);
  immutable_queue<T> dequeue();
  T peek();
  int size();
  bool empty() { 
    return front_.empty() && rear_.empty();
  }

private:
  List front_, rear_; // two stacks to mimic queue

  // utility list class
  class List
  {
    struct Node
    {
      Node(T x, shared_ptr<Node > &tail) 
        : val_(x), next_(tail) {}

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
      shared_ptr<Node> next_;
    };

  public:
    List(): count_(0), head_(nullptr) {}
    List(T x, List tail): head_(make_shared<Node>(x, tail.head_)){
      count_ = 1 + tail.count_;
    }

    int size() { return count_;}

    bool empty() { return count_ == 0;}

    T getHead() { assert(!empty()); return head_->val_;}

    List getTail() { assert(!empty()); return List(head_->next_, count_-1);}

    List addHead(const T &x) {
      return List(x, *this);
    }

    // *this should not be changed
    List reverse() {
      List new_list;
      List it = *this; // make a "copy" first
      for(int i=0; i<size(); ++i) {
        new_list = new_list.addHead(it.getHead());
        it = it.getTail();
      }
      return new_list;
    }
  private:
    explicit List(shared_ptr<Node > tail, int count) 
      : head_(tail), count_(count) {}

    shared_ptr<Node > head_;
    int count_;
  };

};

/**
 * requires default ructor
 */
template<typename T>
immutable_queue<T>::immutable_queue()
{
  front_ = List();
  rear_ = List();
}

template<typename T>
immutable_queue<T>::immutable_queue(List front, List rear)
{
  // front is empty only if rear is empty too
  if(front.empty() && !rear.empty()) {
    this->front_ = rear.reverse();
    this->rear_ = List();
  }
  else {
    this->front_ = front;
    this->rear_ = rear;
  }
  front = List();
  rear = List();
}

/**
 * default destructor
 */
template<typename T>
immutable_queue<T>::~immutable_queue()
{
}

/**
 * Returns the queue that adds an item into the tail of this queue without
 * modifying this queue.
 * 
 * <pre>
 * e.g.
 *  When this queue represents the queue (2,1,2,2,6) and we enqueue the value 4 into this queue,
 *  this method returns a new queue (2,1,2,2,6,4)
 *  and this object still represents the queue (2,1,2,2,6)
 * </pre>
 * 
 * @param e
 * @return
 */
template<typename T>
immutable_queue<T> immutable_queue<T>::enqueue(const T &element)
{
  //make this method faster
  return immutable_queue<T>(front_, rear_.addHead(element));
}

/**
 * Returns the queue that removes the object at the head of this queue
 * without modifying this queue.
 * 
 * <pre>
 * e.g.
 *  When this queue represents the queue (7,1,3,3,5,1) .
 *  this method returns a new queue (1,3,3,5,1)
 *  and this object still represents the queue (7,1,3,3,5,1)
 * </pre>
 * 
 * If this queue is empty, throws range_error
 * 
 * @param e
 * @return
 */
template<typename T>
immutable_queue<T> immutable_queue<T>::dequeue()
{
  //make this method faster
  if(empty()) {
    throw range_error("Opps, this queue is empty, nothing to dequeue");
  }
  return immutable_queue<T>(front_.getTail(), rear_);
}

/**
 * Looks at the object which is the head of this queue without removing it
 * from the queue.
 * 
 * <pre>
 * e.g.
 *  When this queue represents the queue (7,1,3,3,5,1) .
 *  this method returns 7 and this object still represents the queue (7,1,3,3,5,1)
 * </pre>
 * 
 * If this queue is empty, throws range_error
 * 
 * @param e
 * @return
 */
template<typename T>
inline T immutable_queue<T>::peek()
{
  if(empty()) {
    throw range_error("Opps, this queue is empty. nothing to peek");
  }
  return front_.getHead();
}

/**
 * Return the number of objectes in this queue
 * @return 
 */
template<typename T>
inline int immutable_queue<T>::size()
{
  return front_.size() + rear_.size();
}


int main(void)
{
   return 0;
}
