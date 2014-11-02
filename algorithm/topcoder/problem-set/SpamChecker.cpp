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
class SpamChecker
{
public:
string spamCheck(string judgeLog, int good, int bad)
{
  long long score = 0;
  for(size_t i=0; i<judgeLog.size(); ++i)
  {
    if(judgeLog[i] == 'o')
      score += good;
    else
      score -= bad;
    if(score < 0) return string("SPAM"); 
  }
return string("NOT SPAM") ;
}


/*
*/

};// BEGIN CUT HERE
/*
int main(){
SpamChecker ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
