/**
 * @file max_product.cc
 * @brief max contiguous product of a list
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2014-12-29
 */

#include <bits/stdc++.h>
using namespace std;

int MaxProduct(int *a, int n)
{
    assert(a != NULL && n > 0);
    int local_max = a[0], local_min = a[0];
    int global = a[0];
    for(int i=1; i<n; ++i)
    {
        int x = local_min * a[i];
        int y = local_max * a[i];
        local_min = min(a[i], min(x, y));
        local_max = max(a[i], max(x, y));
        global = max(global, local_max);
    }
    return global;
}

int main(void)
{
    int a[] = {2,3,-4, 1};
    cout << MaxProduct(a, sizeof(a)/sizeof(int)) << endl;
    return 0;
}
