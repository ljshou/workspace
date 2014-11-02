/* utilize DP to solve optimal MatrixChainMultiply Order */
#include <iostream>
using namespace std;
const int maxNum=10000000;
const int N=100;

void PrintOptimalParent(int s[][N], int i, int j)
{
  if(i==j) cout << "A" << i;
  else{
    cout << "(";
    PrintOptimalParent(s,i,s[i][j]);
    PrintOptimalParent(s,s[i][j]+1,j);
    cout << ")";
  }
}

void MatrixChainOrder(int *p, int n)
{
  int j;
  int m[N][N], s[N][N];
  for(size_t i=1; i<=n; ++i)
    m[i][i] = 0;
  for(int l=2; l<=n; ++l) //l is the chain length
  {
    for(int i=1; i<=n-l+1; ++i)
	{
	  j = i+l-1;
	  m[i][j] = maxNum;
	  for(int k=i; k<j; ++k)
	  {
	    if(m[i][j] > m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]){
		  m[i][j] = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
		  s[i][j] = k;
		}
	  }
	}
  }
  cout << "minimum: " << m[1][n] << endl;
  PrintOptimalParent(s,1,n);
  cout << endl;
}

int LookUp(int m[][N], int s[][N], int *p, int i, int j)
{
  if(m[i][j] < maxNum)
    return m[i][j];

  if(i==j)
     m[i][j] = 0;
  else
    for(int k=i; k<j; ++k){
      int q = LookUp(m,s,p,i,k)+LookUp(m,s,p,k+1,j)+p[i-1]*p[k]*p[j];
      if(q < m[i][j]){
	    m[i][j] = q; 
	    s[i][j] = k;
	  }
    }
  return m[i][j];
}

void MemorizeMatrixChain(int *p, int n)
{
  int m[N][N], s[N][N];

  for(size_t i=1; i<=n; ++i)
    for(size_t j=1; j<=n; ++j)
	  m[i][j] = maxNum;

  cout << "minimum: " << LookUp(m, s, p, 1, n) << endl;
  PrintOptimalParent(s,1,n);
  cout << endl;
}

int main()
{
  int p[N]={30,35,15,5,10,20,25};
  cout << "Method 1: (down to up)" << endl;
  MatrixChainOrder(p, 6);
  cout << endl << "Method 2: (top to down)" << endl;
  MemorizeMatrixChain(p, 6);
  return 0;
}
