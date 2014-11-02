#include <ctime>
#include <iostream>
using namespace std;

typedef unsigned long ULongLong;

ULongLong Count1InInteger(ULongLong n)
{
  ULongLong num(0);
  while(n != 0)
  {
    num += (n % 10 == 1)?1:0;
	n /= 10;
  }
  return num;
}

ULongLong F(ULongLong n)
{
  ULongLong num(0);
  for(ULongLong i=1; i<=n; ++i)
    num += Count1InInteger(i);
  return num;
}

int main()
{
  ULongLong n = 100000000;
  clock_t start = clock();
  cout << F(n) << endl;
  clock_t finish = clock();
  cout << "it takes " << static_cast<double>(finish - start)/CLOCKS_PER_SEC << endl;
  return 0;
}
