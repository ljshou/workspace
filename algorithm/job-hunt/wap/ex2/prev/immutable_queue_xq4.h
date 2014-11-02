#include <iostream>
#include <stdexcept>
#include <assert.h>
#include <memory>

#include <stdlib.h>

using namespace std;

template <class T>
struct Item
{
    T _val;
    shared_ptr<const Item> _next;

    Item(T v, std::shared_ptr<const Item> const &n):_val(v),_next(n){}
    Item(){}
};

template <class T>
class List
{

private:
    explicit List(std::shared_ptr<const Item<T> > items, int count_) : _head(items), count(count_){}
public:
    List():count(0),_head(nullptr){}
    List(T v, List const & tail):_head(std::make_shared<Item<T> >(v, tail._head)){count = 1+ tail.size();} 
    bool empty() const {return _head == nullptr;}
    T front() const
    {
      if(empty())
        throw range_error("Out of Range!!!");
        assert(!empty());
        return _head->_val;
    }
    List pop_front() const
    {
      if(empty())
        throw range_error("Out of Range!!!");
        assert(!empty());
      return List(_head->_next, count-1); //need a ctor
    }
    List push_front(T v) const
    {
        return List(v, *this);
    }
    int size() const
    {
      return count;
    }
    List reverse()
    {
      List ret;
      List temp = *this;
      for(int i=0; i < count;++i)
      {
        ret = ret.push_front(temp.front());
        temp = temp.pop_front();
      }
      return ret;
    }
private:
    std::shared_ptr<const Item<T> > _head;
    int count;
};
template<typename T>
class immutable_queue
{
private:
  explicit immutable_queue(List<T> _s_push, List<T> _s_pop);
public:
  immutable_queue();
  ~immutable_queue(){}
  immutable_queue<T> enqueue(const T &element);
  immutable_queue<T> dequeue();
  T peek();
  int size();
  bool empty() { 
    return s_push.empty() && s_pop.empty();
  }

private:
  List<T> s_push;
  List<T> s_pop;
};
template<typename T>
immutable_queue<T>::immutable_queue()
{
  s_push = List<T>();
  s_pop = List<T>();
  //count = head.size() + tail.size();
}

template<typename T>
immutable_queue<T>::immutable_queue(List<T> _s_push, List<T> _s_pop)
{
  /*
  if(_s_push.empty() && _s_pop.empty())
  {
    throw range_error("out of range!!!");
  }
  */
  s_push = _s_push;
  s_pop = _s_pop;
  
}

template<typename T>
immutable_queue<T> immutable_queue<T>::enqueue(const T &element)
{
  immutable_queue<T> ret = immutable_queue<T>(s_push.push_front(element), s_pop);
  return ret;
}

template <typename T>
immutable_queue<T> immutable_queue<T>::dequeue()
{ 
  if(s_push.empty() && s_pop.empty())
  {
    throw range_error("Out of range!!! dequeue");
  }
  if(s_pop.empty())
  {
    s_pop = s_push.reverse();
    s_push = List<T>();
  }

  immutable_queue<T> ret = immutable_queue<T>(s_push, s_pop.pop_front());
  return ret;
}

template<typename T>
T immutable_queue<T>::peek()
{
  if(s_push.empty() && s_pop.empty())
  {
    throw range_error("Out of range!!! peek");
  }
  if(s_pop.empty())
  {
    s_pop = s_push.reverse();
    s_push = List<T>();
  }
  return s_pop.front();

}

template<typename T>
int immutable_queue<T>::size()
{
  return s_push.size() + s_pop.size();
}

/*
int main()
{
    immutable_queue<int> p;
    assert(p.size() ==  0);
    p = p.enqueue(2);
    assert(p.size() ==  1);
    p = p.enqueue(9);
    assert(p.peek() ==  2);
    assert(p.size() ==  2);
    p = p.dequeue();
    assert(p.peek() == 9);
    p = p.enqueue(10);
    assert(p.peek() ==  9);
    p = p.dequeue();
    assert(p.peek() ==  10);
    p = p.dequeue();
    assert(p.size() == 0);

	immutable_queue<int> q;
    immutable_queue<int> q1 = q.enqueue(1);
    immutable_queue<int> q12 = q1.enqueue(2);

    immutable_queue<int> q123 = q1.dequeue();



    if(q.empty())
        cout << "q is empty..." << endl;

    return 0;
}

*/
/*

template <class T, class F>
void forEach(List<T> lst,F f)
{
  if(!lst.empty())
  {
    f(lst.front());
    forEach(lst.pop_front(),f);
  }
}
template <typename T>
void print(List<T> lst)
{
  forEach(lst,[](T v){
    cout << "(" << v << ")" ;});
  cout << endl;
}
*/


