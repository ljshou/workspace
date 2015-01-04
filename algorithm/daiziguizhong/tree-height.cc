/**
 * @file tree-height.cc
 * @brief compute the height of a tree
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <vector>
using namespace std;

int Depth(int i, const vector<int> &vec, vector<int> &depth)
{
    if(vec[i] == -1) return depth[i] = 0;
    else if(depth[i] != -1) return depth[i];
    return depth[i] = 1 + Depth(vec[i], vec, depth);
}

int Height(const vector<int> &vec)
{
    const int n = vec.size();
    if(n < 2) return n;
    vector<int> depth(n, -1);
    for(int i=0; i<n; ++i) {
        Depth(i, vec, depth);
    }
    return *max_element(depth.begin(), depth.end());
}

int main(void)
{
    vector<int> vec{-1, 0, 0, 2};
    cout << Height(vec) << endl;
    return 0;
}
