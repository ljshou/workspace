/**
 * @file median.cc
 * @brief return kth largest number
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <cassert>
using namespace std;

int RandomPivot(int *a, int left, int right)
{
    assert(a != nullptr);
    int index = rand() % (right - left+1) + left;
    swap(a[right], a[index]);

    int i(0), j(0);
    int x = a[right]; //pivot
    for(i=j=left; j<right; ++j) 
    {
        if(a[j] < x) swap(a[i++], a[j]);
    }
    swap(a[right], a[i]);
    return i;
}

int KthLargest(int *a, int left, int right, int k)
{
    assert(a != nullptr && left <= right);
    int q = RandomPivot(a, left, right);
    int index = q - left + 1; //start from 1
    if(index == k) return a[q];
    else if(index > k) return KthLargest(a, left, q-1, k);
    else return KthLargest(a, q+1, right, k-index);
}

int Median(int *a, int n)
{
    return KthLargest(a, 0, n-1, n/2);
}

int main(void)
{
    int a[] = {2,3,1,0,0,4,1,0};
    cout << Median(a, sizeof(a)/sizeof(int)) << endl;
    return 0;
}
