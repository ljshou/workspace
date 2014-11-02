#include <iostream>
using namespace std;
int gcd(int a, int b)
{
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(void)
{
  int a = 12, b = 16;
  cout << gcd(a, b);
  return 0;
}
