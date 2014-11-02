/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-11-02
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(void)
{
  string str;
  while(getline(cin, str)) {
	stringstream s(str);
	int x;
	while(s >> x) {
	  cout << x << " ";
	}
	cout << endl;
  }
  return 0;
}

