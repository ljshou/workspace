// copyright @ L.J.SHOU Mar.05, 2014
// 2 sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(NlgN)
void TwoSumVersion1(vector<int> &a, int sum)
{
  if(a.size() < 2)
    return;

  for(vector<int>::iterator it = a.begin(); it != a.end(); ++it)
  {
    if(binary_search(a.begin(), it, sum - *it)
	    || binary_search(it+1, a.end(), sum - *it))
	{
	  cout << *it << " " << sum - *it << endl;
	  return;
	}
  }
}

// two pointers O(N)
void TwoSumVersion2(vector<int> &a, int sum)
{
  vector<int>::iterator left(a.begin()), right(a.end()-1); 

  while(left < right)
  {
    if(*left + *right < sum){
	  ++ left;
	}
	else if(*left + *right > sum){
	  -- right;
	}
	else{
	  cout << *left << " " << *right << endl;
	  return;
	}
  }
}

int main(void)
{
  int a[]={1,2,4,7,11,15}; 
  vector<int> vec(a, a+sizeof(a)/sizeof(int));

  TwoSumVersion1(vec, 15);
  TwoSumVersion2(vec, 15);

  return 0;
}
