#include <iostream>
using namespace std;

void HollandFlag(int *a, int n)
{
   int i,j,k;
	 for(i=0,j=n-1,k=0; k<n && k<=j; ++k)
	 {
	   if(a[k] == 0) swap(a[k], a[i++]);
		 else if(a[k] == 2) swap(a[k--], a[j--]);
	 }
}

int main()
{
  int a[]={0,0,1,2,1,0,0,0,1,};
	HollandFlag(a, sizeof(a)/sizeof(int));
	for(int i=0; i<sizeof(a)/sizeof(int); ++i)
	  cout << a[i] << " ";
	cout << endl;
	return 0;
}
