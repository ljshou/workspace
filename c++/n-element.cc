// copyright @ L.J.SHOU Feb.23, 2014
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
  int a[]={3,5,2,6,1,4};

  nth_element(a, a+3, a+sizeof(a)/sizeof(int));
  cout << "The fourth element is: " << a[3] << endl; 
  
  // output array a[]
  copy(a, a+sizeof(a)/sizeof(int), 
          ostream_iterator<int>(cout, " "));
  return 0;
}
