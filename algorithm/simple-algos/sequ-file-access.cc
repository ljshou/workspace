// copyright @ L.J.SHOU Dec.10, 2013
// O(lgn) to access the ith row
// Problem 14.6 from Programming Pearls
#include <iostream>
using namespace std;

void Path(int n)
{
  if(n == 0)
  {
    cout << "start at 0; ";
	return;
  }
  if(n%2 == 0)//even
  {
    Path(n/2);
	cout << "double to " << n << "; ";
  }
  else
  {
    Path(n-1);
	cout << "Increment to " << n << "; ";
  }
}

int main(void)
{
  Path(15);
  cout << endl;
  return 0;
}
