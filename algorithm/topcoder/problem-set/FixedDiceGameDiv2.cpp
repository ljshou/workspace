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

class FixedDiceGameDiv2
{
public:
  double getExpectation(int a, int b)
  {
    int count(0), sum(0);
    for(; a>0; --a) {
      count += min(a-1, b);
      sum += min(a-1, b) * a;
    }

    return double(sum) / count;
  }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
