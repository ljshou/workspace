// copyright @ L.J.SHOU Dec.03, 2013
// rotate a[N][N] by 90 degrees
#include <iostream>
using namespace std;
#define Max 100
void Transpose(int (*a)[Max], int n)
{
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
	  swap(a[i][j], a[j][i]);
}

void Rotate(int (*a)[Max], int n)
{
  int i, j;
  
  Transpose(a, n);
  i=0; j=n-1;
  while(i<j)
  {
    for(int k=0; k<n; ++k)
	  swap(a[k][i], a[k][j]);
	++i;
	--j;
  }
}

int main(void)
{
  int a[4][Max]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  Rotate(a, 4);
  for(int i=0; i<4; ++i)
  {
    for(int j=0; j<4; ++j)
	  cout << a[i][j] << " ";
	cout << endl;
  }
  return 0; 
}
