#include <iostream>
using namespace std;
const size_t N=0x7FFFFFF;
const int M=999;

void Normal(void)
{
  int x;
  for(size_t i=0; i<N; ++i)
    x = M%2;
}

void New(void)
{
  int x;
  for(size_t i=0; i<N; ++i)
  { 
    x = M;
    while(x/2)
	  x -= 2;
  }
}

int main(void)
{
  Normal(); 
  New();
  return 0;
}
