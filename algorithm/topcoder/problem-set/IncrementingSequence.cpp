#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <bits/stdc++.h>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class IncrementingSequence
{
public:
string canItBeDone(int k, vector <int> A)
{
  int a[51] = {0};
  const int n = A.size();
  for(auto x : A) ++ a[x];
  for(int i=n; i>0; --i) {
    if(a[i] < 1) {
      int j=i-k;
      while(j > 0 && a[j] < 1) j -= k;
      if(j <= 0) return "IMPOSSIBLE";
      else --a[j];
    }
  }

  return string("POSSIBLE") ;
}

/*
*/
};// BEGIN CUT HERE
/*
int main(){
IncrementingSequence ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
