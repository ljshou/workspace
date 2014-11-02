/* copyright @ L.J.SHOU Nov.28, 2013
   Euclidean algorithm 
*/

#include <iostream>
#include <cmath>
using namespace std;

int Gcd(int a, int b)
{
  a = abs(a);
  b = abs(b);
  if(b == 0) return a;
  else return Gcd(b, a%b);
}

int GcdIterative(int a, int b)
{//both integers non-zero
  while(a != b)
  {
    if(a > b) a -= b;
	else b -= a;
  }
  return a;
}

int main()
{
  int a, b;
  cout << "Please input two integers: " << endl;
  cin >> a >> b;
  cout << "GCG(a,b): " << Gcd(a, b) << endl;
  cout << "GCGIterative(a,b): " << GcdIterative(a, b) << endl;
}
