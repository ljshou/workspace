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
class FizzBuzzTurbo
{
public:
vector<long long> counts(long long A, long long B)
{
    long long n1(0), n2(0), n3(0);
    long long i = A;
    for(; i<=B; ++i)
    {
      if(i % 15 == 0) ++n3;
      else if(i % 3 == 0) ++ n1;
      else if(i % 5 == 0) ++ n2;
      //else
    }
    vector<long long> res; 
    res.push_back(n1);
    res.push_back(n2);
    res.push_back(n3);
    return res;
}
};

