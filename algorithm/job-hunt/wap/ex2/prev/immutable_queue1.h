#include <iostream>
#include <stdexcept>
#include <queue>
using std::cout;
using std::endl;
using std::queue;
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

private:
  immutable_queue(const queue<T> &q) :q_(q) {}
  queue<T> q_;
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
  //cout << "destructor called" << endl;
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
  queue<T> new_queue = q_;
  new_queue.push(element);
  return new_queue;
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
  if(q_.empty()) throw range_error("queue is empty");

  queue<T> new_queue = q_;
  new_queue.pop();
  return new_queue;
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
  if(q_.empty()) throw range_error("queue is empty");
  return q_.front();
}

/**
 * Return the number of objectes in this queue
 * @return 
 */
template<typename T>
inline int immutable_queue<T>::size()
{
  return q_.size();
}

