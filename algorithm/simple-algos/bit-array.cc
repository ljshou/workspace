//copyright @ L.J. SHOU Dec.0SHIFT, 201SHIFT
// bit array
#include "bit-array.h"
#include <iostream>
using namespace std;
#define BITSPERCHAR 8
#define SHIFT 3
#define MASK 0x7

void SetBit(char bit_array[], unsigned n, unsigned bit_number)
{
  if(bit_number < 0 || bit_number >= n*BITSPERCHAR)
  {
    cerr << "index out of Range" << endl;
	return;
  }
  //bit_array[bit_numer/BITSPERCHAR] |= (1 << (bit_number % BITSPERCHAR));
  bit_array[bit_number>>SHIFT] |= (1 << (bit_number & MASK));
}

void ClearBit(char bit_array[], unsigned n, unsigned bit_number)
{
  if(bit_number < 0 || bit_number >= n*BITSPERCHAR)
  {
    cerr << "index out of Range" << endl;
	return;
  }
  bit_array[bit_number>>SHIFT] &= ~(1 << (bit_number & MASK));
}

void AssignBit(char bit_array[], unsigned n, unsigned bit_number, int value)
{
  if(bit_number < 0 || bit_number >= n*BITSPERCHAR)
  {
    cerr << "index out of Range" << endl;
	return;
  }
  if(!value)
    ClearBit(bit_array, n, bit_number);
  else
    SetBit(bit_array, n, bit_number);
}

int TestBit(char bit_array[], unsigned n, unsigned bit_number)
{
  if(bit_number < 0 || bit_number >= n*BITSPERCHAR)
  {
    cerr << "index out of Range" << endl;
	return -1;
  }
  return (bit_array[bit_number>>SHIFT] & (1 << (bit_number & MASK)));
}

int main(void)
{
  char bit_array[2];
  int n = sizeof(bit_array);
  for(int i=0; i<n*8; ++i)
    ClearBit(bit_array, n, i);
  SetBit(bit_array, n, 0);
  SetBit(bit_array, n, 8);
  cout << TestBit(bit_array, n, 8) << endl;
  cout << static_cast<unsigned>(bit_array[1]) << endl;
  return 0;
}
