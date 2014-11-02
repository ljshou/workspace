#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = 0xffffff;
const double eps = 1e-6 ; 
class RedPaint
{
public:
double expectedCells(const int N)
{
  double f[2][N+1][N+1];
  fill(&f[0][0][0], &f[0][0][0]+(2)*(N+1)*(N+1), 0.0);

  f[0][0][0] = 1.0;
  for(int i=1; i<=N; ++i)
  {
    for(int j=0; j<=i; ++j)
    {
      for(int k=0; k<=i-j; ++k)
      {
        if(j == 0 && k == 0){
          f[i%2][0][0] = 0.0;
        }
        else if(j == 0){
           f[i%2][j][k] = 0.5*(f[(i-1)%2][0][k-1] + f[(i-1)%2][1][k-1]);
        }
        else if(k == 0){
           f[i%2][j][k] = 0.5*(f[(i-1)%2][j-1][0] + f[(i-1)%2][j-1][1]);
        }
        else
           f[i%2][j][k] = 0.5*(f[(i-1)%2][j-1][k+1] + f[(i-1)%2][j+1][k-1]);
      }
    }
  }

  double res(0);
  for(int j=0; j<=N; ++j)
  {
    for(int k=0; k<=N-j; ++k)
    {
      res += f[N%2][j][k] * (j+k+1);
    }
  }
  return res;
}

};

/*
int main(void)
{
  RedPaint ob;
  int n;
  cin >> n;
  cout << ob.expectedCells(n) << endl;
  return 0;
}
*/
