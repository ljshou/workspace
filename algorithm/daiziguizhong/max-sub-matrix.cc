/**
 * @file max-sub-matrix.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-18
 */
#include <iostream>
#include <vector>
using namespace std;

int maxArray(vector<int>::iterator first, vector<int>::iterator second)
{
    if(first == second)
        return 0;
    int res(0), sum(0);
    for(auto it=first; it!=second; ++it) {
        sum += *it;
        if(sum < 0) sum = 0;
        res = max(res, sum);
    }
    return res;
}

int maxRectSum(vector<vector<int> > &matrix) {
    if(matrix.empty() || matrix.front().empty())
        return 0;
    const int m = matrix.size(), n = matrix.front().size();
    vector<vector<int> > sum(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            sum[i][j] = sum[i-1][j] + matrix[i-1][j-1];
        }
    }

    int res = 0;
    vector<int> vec(n+1, 0);
    for(int up=1; up<=m; ++up) {
        for(int down=up; down<=m; ++down) {
            for(int i=1; i<=n; ++i) {
                vec[i] = sum[down][i] - sum[up-1][i];
            }
            res = max(res, maxArray(vec.begin()+1, vec.end()));
        }
    }
    return res;
}

void Test()
{
    vector<vector<int> > m{{1,3}};
    cout << maxRectSum(m) << endl;
}

int main(void)
{
    Test();
    return 0;
}
