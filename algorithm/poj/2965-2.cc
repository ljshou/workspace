/**
 * @file 2965-2.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-29
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)

bool f[4][4] = {false};
int main(void)
{
  char c;
  For(i, 4)
	For(j, 4) {
	  cin >> c;
	  if(c == '+') {
		f[i][j] = !f[i][j];
		For(k, 4) {
		  f[i][k] = !f[i][k];
		  f[k][j] = !f[k][j];
		}
	  }
	}
  
  int count = 0;
  For(i, 4)
	For(j, 4)
	  if(f[i][j]) ++count;
  cout << count << endl;
  For(i, 4)
	For(j, 4)
	  if(f[i][j]) cout << i+1 << " " << j+1 << endl;

  return 0;
}
