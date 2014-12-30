/**
 * @file min_element.cc
 * @brief find min element in a rotated sorted array
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2014-12-29
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int vec[N];

int MinElement(int *a, int n)
{
    /* a[0] - a[left] increasing
     * a[left+1] - a[n-1] increasing */
    assert(a != NULL);
    if(n <= 0) return -1;
    int left(0), right(n-1), mid(mid);
    while(a[left] >= a[right])
    {
        cout << left << " " << right << endl;
        if(left + 1 == right) return a[right];

        mid = left + (right - left)/2;
        if(a[left] == a[mid] && a[mid] == a[right])
            return *min_element(a+left, a+right+1);
        if(a[left] <= a[mid]) {
            left = mid;
        }
        else if(a[mid] <= a[right]) {
            right = mid;
        }
    }
    return a[mid];
}
int main(void)
{
    int n(0);
    srand(time(0));
    n = rand() % N + 1;
    for(int i=0; i<n; ++i)
        vec[i] = rand() % N;
    sort(vec, vec+n);
    assert(MinElement(vec,n) == *min_element(vec, vec+n));
    return 0;
}
