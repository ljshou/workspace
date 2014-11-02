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
#include <bits/stdc++.h>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class NegativeGraphDiv2
{
public:
  //use floyd to compute distance between every two nodes
  //use dynamic programming
  long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges)
  {
    if(s.empty()) return 0;
    typedef long long ll;
    int d[N][N];
    fill_n(&d[0][0], N*N, 1000000000);
    for(int i=0; i<N; ++i) d[i][i] = 0;

    for(int i=0; i<weight.size(); ++i) {
      d[s[i]-1][t[i]-1] = min(weight[i], d[s[i]-1][t[i]-1]);
    }

    //floyed
    for(int k=0; k<N; ++k) 
      for(int i=0; i<N; ++i) 
        for(int j=0; j<N; ++j) 
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);


    //Step 2: D.P.
    ll f[charges + 1][N];
    for(int i=0; i<N; ++i) f[0][i] = d[0][i]; //distance from Node 0 to Node i

    for(int k=1; k<=charges; ++k) {
      for(int i=0; i<N; ++i) {
        f[k][i] = f[k-1][i];
        for(int j=0; j<weight.size(); ++j) {
          int u = s[j]-1;
          int v = t[j]-1;
          f[k][i] = min(f[k][i], f[k-1][u]-weight[j]+d[v][i]);
        }
      }
    }

    return f[charges][N-1] ;
  }


  /*
  */

};// BEGIN CUT HERE
/*
int main(){
  NegativeGraphDiv2 ___test;
  ___test.run_test(-1);
  //getch() ;
  return 0;
}
*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
