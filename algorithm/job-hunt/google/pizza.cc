/**
 * @file pizza.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2014-12-28
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int a[N];
bool flag[N];
int n;

int FindLeftNeighbor(int i)
{
    int left = (i-1+n)%n;
    while(left != i)
    {
        if(flag[left] == false)
            return left;
        left = (left - 1 + n) % n;
    }
    return left;
}

int FindRightNeighbor(int i)
{
    int right = (i+1)%n;
    while(right != i)
    {
        if(flag[right] == false)
            return right;
        right = (right + 1) % n;
    }
    return right;
}

int MaxProfit()
{
    int res = 0;
    int left(0), right(0);
    for(int i=0; i<n; ++i) 
    {
        if(!flag[i])
        {
            left = FindLeftNeighbor(i);
            right = FindRightNeighbor(i);
            flag[i] = flag[left] = flag[right] = true;
            res = max(res, a[i] + MaxProfit());
            //restore state
            flag[i] = flag[left] = flag[right] = false;
        }
    }
    return res;
}

int helper(int *a, int len, int count)
{
    vector<vector<int> > f(len+1, vector<int>(count+1, 0));
    for(int j=1; j<=count; ++j)
        f[1][j] = max(0, a[0]);
    for(int i=2; i<=len; ++i)
    {
        for(int j=1; j<=min(i, count); ++j) 
        {
            f[i][j] = max(f[i-2][j-1]+a[i-1], f[i-1][j]);
        }
    }
    return f[len][count];
}

int MaxProfit2()
{
    int res(0);
    //pick a[n-1]
    res = max(res, a[n-1] + helper(&a[1], n-3, n/3 - 1));
    //do not pick a[n-1]
    res = max(res, helper(&a[0], n-1, n/3));
    return res;
}

int main(void)
{
    srand(time(0));
    for(int i=0; i<10000; ++i)
    {
        n = (rand() % 6 + 1) * 3; 
        fill(flag, flag + n, false);
        for(int j=0; j<n; ++j)
            a[j] = rand() % 1000;
        assert(n % 3 == 0);

        cout << MaxProfit() << endl;
        cout << MaxProfit2() << endl;
        assert(MaxProfit() == MaxProfit2());
    }
    return 0;
}
