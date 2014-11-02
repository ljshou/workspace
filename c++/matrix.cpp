#include <iostream>
#include "matrix.h"
int main()
{
  try{
   Matrix<int> m(3,3);
   cout << m;
   for(int i=1; i<=3; i++)
    for(int j=1; j<=3; j++)
      m(i,j)=i+j;
   std::cout << m;
   Matrix<int> m2(m);
   m2 += m;
   std::cout << m2;
  }catch(...){
    cerr << "an error occured!!!" << std::endl;
  }
  return 0;
}
