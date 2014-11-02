#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

void cmp(const void *lhs, const void *rhs)
{
  return *(int*)lhs - *(int*)rhs;
}

int main()
{
  int a[]={9,8,7,6,5,4,3,2,1,0};
  //qsort(a, 10, sizeof(int), cmp);
  sort(a, a+9);
  for(size_t i=0; i!=10; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
