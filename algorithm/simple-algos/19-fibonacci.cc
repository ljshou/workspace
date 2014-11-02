// copyright @ L.J.SHOU Mar.12, 2014
// fibonacci numbers
// O(lgN) 
#include <iostream>
#include <cstring>
using namespace std;

void multiply(int a[], int b[], int result[])
{
  result[0] = a[0] * b[0] + a[1] * b[2];
  result[1] = a[0] * b[1] + a[1] * b[3];
  result[2] = a[2] * b[0] + a[3] * b[2];
  result[3] = a[2] * b[1] + a[3] * b[3];
}

void power(int a[], int n, int result[])
{
  if(n == 1){
    // memcpy(dest, sours, size);
    memcpy(result, a, 4 * sizeof(int));
	return;
  }

  int tmp[4];
  power(a, n>>1, result);
  multiply(result, result, tmp);

  if(n & 1){ // odd
    multiply(tmp, a, result);
  }
  else{ // even
    memcpy(result, tmp, sizeof(int) * 4);
  }
}

int fibonacci(int n)
{
  if(n == 0) return 0;

  int a[]={1, 1, 1, 0};
  int result[4];

  power(a, n, result);

  return result[1];
}

int main(void)
{
  for(int i=0; i<10; ++i)
    cout << fibonacci(i) << " ";
  cout << endl;

  return 0;
}
