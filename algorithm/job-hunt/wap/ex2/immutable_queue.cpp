//copyrigt @ L.J.SHOU May.25, 2014
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

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
  immutable_queue<T> append(const immutable_queue<T> &rhs);
  immutable_queue<T> dequeue();
  immutable_queue<T> reverse();
  T peek();
  T getMax();
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
        : val_(x), max_(x), next_(tail), len_(1) {
          if(next_) {
            len_ += next_->len_;
            max_ = max(max_, next_->max_);
          }
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
      T max_; // max element in this list
      shared_ptr<Node> next_;
      int len_;
    };

  public:
    List(): head_(nullptr) {}
    List(T x, List tail): head_(make_shared<Node>(x, tail.head_)){
    }

    int size() { return head_? head_->len_: 0;}

    bool empty() { return head_ == nullptr;}

    T getHead() { assert(!empty()); return head_->val_;}

    List getTail() { assert(!empty()); return List(head_->next_); }

    List addHead(const T &x) { return List(x, *this); }

    T getMax() { assert(!empty()); return head_->max_; }

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
    explicit List(shared_ptr<Node > tail) 
      : head_(tail) {}

    shared_ptr<Node > head_;
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

template<typename T>
immutable_queue<T> immutable_queue<T>::append(const immutable_queue<T> &rhs)
{
  immutable_queue<T> temp = rhs;
  immutable_queue<T> res = *this;
  while(!temp.empty())
  {
    res = res.enqueue(temp.peek());
    temp = temp.dequeue();
  }
  return res;
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

template<typename T>
immutable_queue<T> immutable_queue<T>::reverse()
{
  return immutable_queue<T>(rear_, front_);
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

template<typename T>
inline T immutable_queue<T>::getMax()
{
  if(empty()) {
    throw range_error("Opps, this queue is empty.");
  }
  T max_elem = front_.getMax();
  if(!rear_.empty()) max_elem = max(max_elem, rear_.getMax());
  return max_elem;
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
  immutable_queue<int> p1;
  p1 = p1.enqueue(1);
  p1 = p1.enqueue(2);
  p1 = p1.enqueue(3);
  immutable_queue<int> p2;
  p2 = p2.enqueue(4);
  p2 = p2.enqueue(5);
  p2 = p2.enqueue(6);
  p1 = p1.append(p2);
  assert(p1.size() == 6);
  assert(p2.size() == 3);

  immutable_queue<int> temp = p1.reverse();
  while(!temp.empty())
  {
    cout << temp.peek() << " ";
    temp = temp.dequeue();
  }
  cout << endl;

  temp = p1;
  while(!temp.empty())
  {
    cout << temp.peek() << " ";
    temp = temp.dequeue();
  }
  cout << endl;

  assert(p1.size() == 6);
  /*
    immutable_queue<int> q1;
    queue<int> q2, temp;
    int x, max_elem;

    for(int i=0; i<100000; ++i)
    {
      assert(q1.size() == q2.size());
      if(!q1.empty()) {
        assert(q1.peek() == q2.front());
        //compute the max elem of queue
        max_elem = q2.front();
        while(!q2.empty()) {
          max_elem = max(max_elem, q2.front());
          temp.push(q2.front());
          q2.pop();
        }
        q2.swap(temp);
        assert(q1.getMax() == max_elem); 
      }
      // pop
      if(rand() % 3 == 0 ) {
        if(q1.empty()) continue;
        q1 = q1.dequeue();
        q2.pop();
      }
      // push
      else {
        x = rand();
        q1 = q1.enqueue(x);
        q2.push(x);
      }
   }
   */

   return 0;
}
