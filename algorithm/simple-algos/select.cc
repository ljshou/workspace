//copyright @ L.J.SHOU Nov.27
#include <iostream>
using namespace std;

const int MaxArraySize=0x1fffff;
int mid_array[MaxArraySize];

int Select(int *a, int left, int right, int i);

void InsertSort(int *a, int left, int right)
{
  int i,j,tmp;
  for(i=left+1; i<=right; ++i)
  {
    tmp = a[i];
	for(j=i; j>left && a[j-1]>tmp; --j)
	  a[j] = a[j-1];
	a[j] = tmp;
  }
}

inline int Medium(int *a, int left, int right)
{
  return a[left+(right-left)/2];
}

int Partition(int *a, int left, int right)
{
  int x = a[right]; //pivot element
  int i,j;
  for(i=j=left; j<right; ++j)
    if(a[j] < x) swap(a[j], a[i++]);
  swap(a[i], a[right]);
  return i;
}

int PartitionSelect(int *a, int left, int right)
{
  int length = right - left + 1;
  int p(0);//medium of n/5 mediums

  int i, j=0, remainder=length % 5;
  for(i=left; i<=right-4; i+=5)
  {
    InsertSort(a, i, i+4);
	mid_array[j] = a[i+2];
	++j;
  }
  if(remainder > 0)
  {
    InsertSort(a, right-remainder+1, right);
    mid_array[length/5] = Medium(a, right - length % 5 + 1, right);
    p = Select(mid_array, 0, length/5, (length/5+1)/2);
  }
  else
  {
    p = Select(mid_array, 0, length/5-1, (length/5)/2);
  }

  swap(a[p], a[right]);
  return Partition(a, left, right);
}

int Select(int *a, int left, int right, int i)
{
  int k, q;
  if(left == right) return a[left];
  q = PartitionSelect(a, left, right); 
  k = q - left + 1;
  if(i == k) return a[q];
  else if(i < k) return Select(a, left, q-1, i);
  else return Select(a, q+1, right, i-k);
}


int main()
{
  int k(5);
  int a[]={10,9,8,7,6, 18,8,0,-1};
  for(size_t i=0; i<sizeof(a)/sizeof(int); ++i)
    cout << a[i] << " ";
  cout << endl;

  for(size_t i=1; i<=sizeof(a)/sizeof(int); ++i)
    cout << "the  " << i << "th smallest number is: " << Select(a, 0, sizeof(a)/sizeof(int)-1, i) << endl;

  cout << "************Curent Array: *****************" << endl;
  for(int i=0; i<sizeof(a)/sizeof(int); ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
