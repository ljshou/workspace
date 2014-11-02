// copyright @ L.J.SHOU Dec.03, 2013
#include<cstring>
#include<iostream>
#include<bitset>
using namespace std;

#define MAX 100
void SetZero(int a[][MAX], int m, int n)
{
  bitset<MAX> row;
  bitset<MAX> col;
  
  //search for zero elements
  for(int i=0; i<m; ++i)
  {
    for(int j=0; j<n; ++j)
	  if(a[i][j] == 0)
	  {
	    row[i] = 1;
		col[j] = 1;
	  }
  }

  //clear rows
  for(int i=0; i<m; ++i)
  {
    if(row[i])
	  memset(&a[i][0], 0, n*sizeof(int));
  }

  //clear cols
  for(int j=0; j<n; ++j)
  {
    if(col[j])
	{
	  for(int i=0; i<m; ++i)
	    a[i][j] = 0;
	}
  }
}

void Print2DArray(int a[][MAX], int m, int n)
{
  for(int i=0; i<m; ++i)
  {
    for(int j=0; j<n; ++j)
	  cout << a[i][j] << " ";
	cout << endl;
  }
}

int main(void)
{
  int a[][MAX]={{1,2,3},{4,0,6}};
  SetZero(a, 2, 3);
  Print2DArray(a, 2, 3);
  return 0;
}
