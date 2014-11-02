#include <ctime>
#include <iostream>
using namespace std;
#define Max(a,b) ((a)>(b)? (a):(b))
double x[10000];
double arrmax(int n)
{
  if(n==1)
    return x[0];
  else
    return Max(x[n-1], arrmax(n-1));
}

int main(void)
{
  for(int i=sizeof(x)/sizeof(double)-1; i>=0; --i)
    x[i] = i;
  time_t start = clock();
  cout << arrmax(sizeof(x)/sizeof(double)) << endl;
  time_t finish = clock();
  cout << "it takes " << static_cast<double>(finish-start)*1e9/CLOCKS_PER_SEC << endl;
  return 0;
}

