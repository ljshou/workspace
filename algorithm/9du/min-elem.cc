/**
 * @file min-elem.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-26
 */

#include <bits/stdc++.h>
using namespace std;

/** 
 * find the minimum element in a rotated sorted array
 */
int MinElem(int *vec, int leftIndex, int rightIndex)
{
  if(leftIndex > rightIndex) throw std::invalid_argument("Invalid parameters");
  if(leftIndex == rightIndex) return vec[leftIndex];
  int midIndex(0);
  while(vec[leftIndex] >= vec[rightIndex])
  {
    if(rightIndex - leftIndex == 1) {
      midIndex = rightIndex;
      break;
    }
    midIndex = leftIndex + (rightIndex-leftIndex)/2;
    if(vec[leftIndex] == vec[rightIndex] && vec[midIndex] == vec[rightIndex]) {
      return *min_element(vec+leftIndex, vec+rightIndex+1);
    }
    //midIndex located in the left part
    if(vec[midIndex] >= vec[leftIndex]) {
      leftIndex = midIndex;
    }
    //midIndex located in the right part
    else if(vec[midIndex] <= vec[rightIndex]) {
      rightIndex = midIndex;
    }
  }
  return vec[midIndex];
}

int main(void)
{
  int vec[1000000];
  int n(0), x;
  while(scanf("%d", &n) != EOF) {
    for(int i=0; i<n; ++i) {
      scanf("%d", &vec[i]);
    }
    cout << MinElem(vec, 0, n-1) << endl;
  }
  return 0;
}
