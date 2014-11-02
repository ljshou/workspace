// copyright @ L.J.SHOU
#include <iostream>
using namespace std;
#define N 10
int main(void)
{
  int flight = 63;

  if(flight == 063)//hex
    cout << "true " << N << endl;
  if(flight & 1) //fligth is odd?
    cout << "odd" << endl;

  return 0;
}
