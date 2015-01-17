/**
 * @file min-insert-chars.cc
 * @brief insert min # of chars to make string palindrome
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-16
 */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int MinInsertions(const string &str)
{
    if(str.empty()) return 0;
    const int n = str.size();
    vector<vector<int> > f(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i)
        f[i][i] = 0;
    for(int gap = 1; gap < n; ++ gap) {
        for(int l=0, h=gap; l<n && h<n; ++l, ++h) {
            f[l][h] = ((str[l] == str[h]) ? f[l+1][h-1] : (1 + min(f[l+1][h], f[l][h-1])));
        }
    }
    return f[0][n-1];
}

int fmiDP(const string &str){
    const int n = str.size();
    //二维数组保存子问题的解，table[i][j]表示str[i,j]转换为回文，需要插入的最少字符数。
    int table[n][n], l, h, gap;

    memset(table, 0, sizeof(table));

    // 外层循环，gap从小到大
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                (min(table[l][h-1], table[l+1][h]) + 1);
    return table[0][n-1];
}


void Test()
{
    assert(MinInsertions("ab") == 1);
    assert(MinInsertions("aa") == 0);
    assert(MinInsertions("abcd") == 3);

    assert(fmiDP("ab") == 1);
    assert(fmiDP("aa") == 0);
    assert(fmiDP("abcd") == 3);
}

int main(void)
{
    Test();
    return 0;
}
