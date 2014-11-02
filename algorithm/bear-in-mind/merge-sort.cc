/* Merge sort implemented by L.J. in Nov.20, 2013 */
/* worst O(nlgn), but require extra memory for Merge() */
/* type num: 3 */
#include <iostream>
using namespace std;

void Merge(int *array, int *tmp_array, int lpos, int rpos, int right_end)
{
  int left_end(rpos-1), num_elements(right_end-lpos+1), tmp_pos(lpos);
	
	//正方向 或者逆方向都可以 
  while(lpos <= left_end && rpos <= right_end)
    if(array[lpos] <= array[rpos]) 
	    tmp_array[tmp_pos++] = array[lpos++];
	  else
	    tmp_array[tmp_pos++] = array[rpos++];

  while(lpos <= left_end)
    tmp_array[tmp_pos++] = array[lpos++];
  while(rpos <= right_end)
    tmp_array[tmp_pos++] = array[rpos++];

  //copy tmp array back
  for(int i=0; i<num_elements; ++i, --right_end)
    array[right_end] = tmp_array[right_end]; 
}

void MSort(int *array, int *tmp_array, int l, int r)
{
  if(l < r)
  {
    int mid = l + (r-l)/2;
	/*
	MergeSort(a, left, mid-1, tmp);
	MergeSort(a, mid, right, tmp);//infinite loop
	Merge(a, left, mid, right, tmp);
	*/
    MSort(array, tmp_array, l, mid);
    MSort(array, tmp_array, mid+1, r);
    Merge(array, tmp_array, l, mid+1, r);
  }
}

void MergeSort(int *array, int length)
{
   int *tmp_array; 
   tmp_array = new int [length];
   if(tmp_array != NULL)
   {
     MSort(array, tmp_array, 0, length-1);
     delete [] tmp_array;
   }
   else
     cerr << "not enough space for tmp array" << endl;
}

int main()
{
  int a[]={1,6,5,3,8,2,0};
  MergeSort(a, sizeof(a)/sizeof(int));
  for(int i=0; i<sizeof(a)/sizeof(int); ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
