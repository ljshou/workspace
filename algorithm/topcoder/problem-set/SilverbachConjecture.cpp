#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class SilverbachConjecture
{
public:
vector <int> solve(int n)
{
  vector<int> res;
  for(int i=2; i<n; ++i)
  {
    if(viable(i) && viable(n-i))
    {
      res.push_back(i);
      res.push_back(n-i);
      break;
    }
  }
  return res;
}
private:
bool viable(int x)
{
  for(int i=2; i<x; ++i)
    if(i * (x/i) == x)
      return true;
  return false;
}


/*
*/

};// BEGIN CUT HERE
/*
int main(){
SilverbachConjecture ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
