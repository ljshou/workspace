// column 12 in Programming Pearls by Knuth
// randomly select m sorted numbers from [0-n)
#include<set>
#include<iostream>
#include<cstdlib>
using namespace std;

void genknuth(int m, int n)
{
  for(int i=0; i<n; ++i)
  {//select m of remaining n-i numbers
    if(rand()%(n-i) < m)
	{
	  cout << i << " ";
	  m -- ;
	}
  }
  cout << endl;
}

void gensets(int m, int n)
{
  set<int> s; 
  int x;
  while(s.size() < m)
  {
    x = rand() % n;
	if(s.count(x) == 0)
	  s.insert(x);
  }
  set<int>::const_iterator it;
  /*
  for(it=s.begin(); it!=s.end(); ++it)
    cout << *it << " ";
  cout << endl;
  */
}

void RandSelect(int m, int n)
{
  //pre 0<=m<=n
  //post m distinct integers from 0..n-1 are printed
  //in increasing order
  if(m>0)
  {
  }
}

int main(void)
{
  srand(time(0));
  int m, n;
  cout << "Please input m and n" << endl;
  cin >> m >> n;
  gensets(m, n);
  return 0;
}
