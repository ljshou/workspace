/*  dynamic programming by L.J. in Oct. 25, 2013 */
#include <iostream>
using namespace std;

const size_t N=100;

void printStations(int l[][N], int st, int n)
{
  if(n>0){
    printStations(l, l[st][n-1], n-1);
    cout << "line: " << st+1 << ", station: " << n << endl;
  }
  else return;
}

void fastWay(int a[][N], int t[][N], int *e, int *x, int n)
{
  int f[2][N], l[2][N], st, min;
  f[0][0] = e[0]+a[0][0];
  f[1][0] = e[1]+a[1][0];
  for(size_t i=1; i<n; ++i){
    if(f[0][i-1]+a[0][i] < f[1][i-1]+t[1][i-1]+a[0][i]){
	  f[0][i] = f[0][i-1]+a[0][i];
	  l[0][i] = 0;
	}
	else{
	  f[0][i] = f[1][i-1]+a[0][i]+t[1][i-1];
	  l[0][i] = 1;
	}

    if(f[1][i-1]+a[1][i] < f[0][i-1]+t[0][i-1]+a[1][i]){
	  f[1][i] = f[1][i-1]+a[1][i];
	  l[1][i] = 1;
	}
	else{
	  f[1][i] = f[0][i-1]+a[1][i]+t[0][i-1];
	  l[1][i] = 0;
	}
  }
  if(f[0][n-1]+x[0] < f[1][n-1]+x[1]){
    min = f[0][n-1]+x[0];
    st = 0;
  }
  else{
    min = f[1][n-1]+x[1];
    st = 1;
  }
  cout << "minimun value: " << min << endl; 
  printStations(l, st, n);
}

int main()
{
  int e[2]={2,4}, x[2]={3,2};
  int a[2][N]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
  int t[2][N]={{2,3,1,3,4},{2,1,2,2,1}};
  fastWay(a,t,e,x,6);
  return 0;
}


