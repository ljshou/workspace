// copyright @ L.J.SHOU Feb.22, 2014
// magic index
#include <iostream>
using namespace std;

// if found, return index;
// if not found, return -1;
int MagicIndex(int A[], int left, int right)
{
	int index(-1);

	if(left <= right)
	{
	  int mid = left + ((right - left) >> 1);  

		if(A[mid] == mid)  return mid;
		else if(A[mid] < mid){
		  index = MagicIndex(A, left, A[mid]); 
		  if(index != -1)  return index;

		  index = MagicIndex(A, mid+1, right); 
		  if(index != -1)  return index;
		}
		else{
		  index = MagicIndex(A, left, mid-1); 
		  if(index != -1)  return index;

		  index = MagicIndex(A, A[mid], right); 
		  if(index != -1)  return index;
		}
	}

	return -1;
}

int main(void)
{
  int a[] = {-10,2,2,2,2,10,12,13,20};

	cout << MagicIndex(a, 0, sizeof(a)/sizeof(int)-1) << endl;

	return 0;
}
