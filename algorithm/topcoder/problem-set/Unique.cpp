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
class Unique
{
public:
string removeDuplicates(string S)
{
  string str;
  set<char> existed;
  for(int i=0; i<S.size(); ++i)
  {
    if(existed.find(S[i]) == existed.end()) 
    {
      str.push_back(S[i]);
      existed.insert(S[i]);
    }
  }
  return str;
}
};

