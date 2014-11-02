/**
 * @file my_list.cc
 * @brief list 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-14
 */

#include "my_list.h"
#include <iterator>
#include <algorithm>
using namespace std;

int main(void)
{
  MyList<int> list1(5, 0);

  list1.insert(list1.end(), 3);
  list1.insert(list1.end(), 2);
  list1.insert(list1.end(), 1);
  list1.insert(list1.end(), 6);
  list1.insert(list1.end(), 4);
  list1.insert(list1.end(), 7);
  list1.insert(list1.end(), 5);

  list1.remove(0);

  list1.sort();

  for(MyList<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    cout << *it << " ";
  cout << endl;
  cout << "reverse: " << endl;
  for(MyList<int>::iterator it = list1.rbegin(); it != list1.end(); --it)
    cout << *it << " ";
  cout << endl;

  return 0;
}
