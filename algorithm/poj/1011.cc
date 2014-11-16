/**
 * @file 1011.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-11-13
 */

#include <iostream>
#include <vector>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
int n;
int a[64+5];

int main(void)
{
  while((cin >> n) && n) {
	For(i, n) {
	  cin >> a[i];
	  cout << a[i] << " ";
	}
	cout << endl;
  }
  return 0;
}
