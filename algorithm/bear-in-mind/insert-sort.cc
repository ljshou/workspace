/* insert sort implemented by L.J. in Nov.20, 2013 */
/* type num: 6 */
#include <iostream>
using namespace std;

void InsertSort(int *a, int length)
{
  int i, j, tmp;
  for(i=1; i<length; ++i)
  {
    tmp = a[i];
    for(j=i; j>0 && tmp < a[j-1]; --j)
	  a[j] = a[j-1];
	a[j] = tmp;
  }
}

int main()
{
  int a[]={10,4,6,7,2,1,3,9,0,};
  InsertSort(a, sizeof(a)/sizeof(int));
  for(int i=0; i<sizeof(a)/sizeof(int); ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
