/**
 * @file source-nodes.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-06
 */

#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, vector<int> &flag, const vector<int> &vec)
{
    if(i < 0 || i >= vec.size()) return -1;
    if(flag[i] != 0) return flag[i];
    flag[i] = -1; //visited
    if(dfs(i+vec[i], flag, vec) == 1) 
        return flag[i] = 1;
    if(dfs(i-vec[i], flag, vec) == 1)
        return flag[i] = 1;
    return flag[i] = -1;
}

vector<int> SourceNodes(const vector<int> &vec, int dest)
{
    if(vec.empty() || dest < 0 || dest >= vec.size()) return vector<int>();
    const int n = vec.size();
    vector<int> flag(n, 0), res;
    flag[dest] = 1;
    for(int i=0; i<n; ++i)
        dfs(i, flag, vec);
    for(int i=0; i<n; ++i) {
        if(flag[i] == 1 && i != dest) 
            res.push_back(i);
    }
    return res;
}

int main(void)
{
    vector<int> vec{1,2,0,3,3,7};
    auto source = SourceNodes(vec, 0);
    copy(source.begin(), source.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
