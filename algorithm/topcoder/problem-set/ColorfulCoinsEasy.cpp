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
#include <set>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class ColorfulCoinsEasy
{
public:
string isPossible(vector <int> values)
{
  if(values.empty()) return string("Possible");
  vector<int> s;
  int div;
  for(int i=values.size()-1; i>0; --i)
  {
    div = values[i] / values[i-1];  
    s.push_back(div - 1);
  }
  sort(s.begin(), s.end(), greater<int>());
  int n = s.size();
  for(int i=0; i<s.size(); ++i)
  {
    if(s[i] < n - i) 
    {
      return string("Impossible");
    }
  }

return string("Possible") ;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
