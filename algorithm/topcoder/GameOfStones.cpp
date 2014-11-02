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
class GameOfStones
{
public:
int count(vector <int> stones)
{
  const int n = stones.size();
  if(n == 0) return 0;
  sort(stones.begin(), stones.end());
  int sum = accumulate(stones.begin(), stones.end(), 0);
  if(sum % n != 0) return -1;
  int avg = sum / n;

  int count = 0;
  int left(0), right(n-1);
  while(left < right) {
    int gap1 = avg - stones[left];
    int gap2 = stones[right] - avg;
    if(gap1 == 0) break;
    if(gap2 == 0) break;
    if(gap1 % 2 != 0) return -1;
    if(gap2 % 2 != 0) return -1;
    
    if(gap1 < gap2) {
      stones[right] -= gap1;
      ++left;
      count += gap1 / 2;
    }
    else if(gap1 > gap2) {
      stones[left] += gap2;
      --right;
      count += gap2 / 2;
    }
    else {
      stones[left] += gap1;
      stones[right] -= gap1;
      ++left, --right;
      count += gap1 / 2;
    }
  }

  return count;
}

/*
*/
};// BEGIN CUT HERE
/*
int main(){
GameOfStones ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
