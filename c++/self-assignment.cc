/**
 * @file self-assignment.cc
 * @brief deal with self-assignment
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-01
 */

#include <bits/stdc++.h>
using namespace std;

class Widget {
public:
  Widget(int x=0): val(new int(x)) {}
  ~Widget() { delete val; }
  Widget(const Widget &rhs): val(new int(*rhs.val)) {}
  //operator =
  Widget& operator=(const Widget &rhs); 

  void print() const { cout << *val << endl; }
  void swap(Widget &rhs) { std::swap(val, rhs.val);}
private:
  int *val;
};

/** wrong version
 * not-safe when self-assignment occurs.
 */
/*
Widget& Widget::operator=(const Widget &rhs) {
  delete val;
  val = new int(*rhs.val);
  return *this;
}

//version 1
Widget& Widget::operator=(const Widget &rhs) {
  if(this == &rhs) return;

  delete val;
  val = new int(*rhs.val);
  return *this;
}

//version2
Widget& Widget::operator=(const Widget &rhs) {
  int *pOld = val;
  val = new int(*rhs.val);
  delete pOld;
  return *this;
}
*/


//version3
Widget& Widget::operator=(const Widget &rhs) {
  Widget temp(rhs);
  swap(temp);
  return *this;
}

/*
//version4
Widget& Widget::operator=(Widget rhs) { //yes, copy by value
  swap(rhs);
  return *this;
}
*/

int main(void)
{
  Widget w1(0);
  Widget *p = &w1;
  *p = w1;
  w1.print();

  return 0;
}

