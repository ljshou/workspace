/**
 * @file vector.cc
 * @brief vector test file 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-09
 */
#include "my_vector.h"
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void)
{
  MyVector<int> vec(5, 1);

  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.insert(vec.begin(), 2, 0);
  vec.pop_back();

  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;

  vec.reserve(30);
  cout << "after reserve: " << endl;
  cout << "capacity: " << vec.capacity() << endl;

  copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  MyVector<int> vec2(vec.begin(), vec.end());
  cout << "vec2's capacity: " << vec2.capacity() << endl;
  vec2.clear();
  copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  const MyVector<int> vec3(vec);
  cout << vec3[0] << endl;

  return 0;
}

