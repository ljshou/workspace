/**
 * @file template-singleton.cc
 * @brief a template singleton class 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-26
 */
template<typename T> 
class Singleton 
{ 
  struct object_creator 
  { 
    object_creator() 
    { 
      Singleton<T>::instance(); 
    } 
    inline void do_nothing() const {} 
  }; 
  static object_creator create_object; 

public : 
  typedef T object_type; 
  static T& instance() 
  { 
    static T obj; 
    //这个do_nothing是确保create_object构造函数被调用 
    //这跟模板的编译有关 
    create_object.do_nothing(); 
    return  obj; 
  } 
}; 

template<typename T> 
typename Singleton<T>::object_creator Singleton<T>::create_object; 

class QMManager 
{ 
protected : 
  QMManager() {} 
  ~QMManager() {} 
  friend class Singleton <QMManager>; 
public : 
  void do_something() {}; 
}; 

int main(void) 
{ 
  Singleton<QMManager>::instance().do_something(); 
  return 0; 
}
