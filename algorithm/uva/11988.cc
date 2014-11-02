/**
 * @file 11988.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-11-01
 */

#include <iostream>
#include <cstring>
using namespace std;

#define For(i,l,r) for(int i=(l); i<=(r); ++i)
const int MAX = 100000 + 10;
int cur, last, next[MAX];
char s[MAX];

int main(void)
{
  while(cin >> s+1) {
	int n = strlen(s+1);
	cur = last = 0;
	next[0] = 0;

	For(i, 1, n) {
	  switch(s[i]) {
		case '[':
		  cur = 0;
		  break;
		case ']':
		  cur = last;
		  break;
		default:
		  next[i] = next[cur];
		  next[cur] = i;
		  if(cur == last) last = i;
		  cur = i;
		  break;
	  }
	}
	//print
	for(int i=next[0]; i!=0; i=next[i]) {
	  cout << s[i];
	}
	cout << endl;
  }
  return 0;
}
