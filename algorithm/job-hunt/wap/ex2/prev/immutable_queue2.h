#include "list_ref.h"
#include <iostream>
#include <stdexcept>
using std::range_error;

/**
 * This class represents an immutable first-in-first-out(FIFO) queue of objects.
 */
template<typename T>
class immutable_queue
{
public:
  immutable_queue();
  ~immutable_queue();
  immutable_queue<T> enqueue(const T &element);
  immutable_queue<T> dequeue();
  T peek();
  int size();
  void print() const { queue_.print(); }

private:
  immutable_queue(const ListRef<T> &queue): queue_(queue) {}
  ListRef<T> queue_;
};

/**
 * requires default constructor
 */
template<typename T>
immutable_queue<T>::immutable_queue()
{
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
immutable_queue<T> immutable_queue<T>::enqueue(const T &x)
{
  //make this method faster
  if(queue_.empty()) {
    ListRef<T> queue; 
    queue.push(x);
    return queue;
  }

  if(queue_.tail_->next != NULL)
  {
    // deep copy
    ListRef<T> queue = queue_.clone();
    queue.push(x);
    return queue;
  }
  else 
  {
    // shallow copy
    ListRef<T> queue = queue_;
    queue.push(x);
    return queue;
  }
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
  if(queue_.empty()) throw range_error("queue is empty");

  ListRef<T> queue(queue_.head_->next, queue_.tail_, queue_.count_-1);
  return queue;
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
  if(queue_.empty()) throw range_error("queue is empty");
  return queue_.head_->val;
}

/**
 * Return the number of objectes in this queue
 * @return 
 */
template<typename T>
inline int immutable_queue<T>::size()
{
  return queue_.size();
}

