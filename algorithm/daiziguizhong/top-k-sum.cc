/**
 * @file top-k-sum.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> TopNSum(const vector<int> &a, const vector<int> &b)
{
    if(a.empty() || b.empty()) return vector<int>();
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for(int i=0; i<a.size(); ++i)
        q.push(make_pair(a[i]+b[0], 0));

    for(int i=0; i<a.size(); ++i) {
        auto x = q.top(); q.pop();
        res.push_back(x.first);
        x.first = x.first - b[x.second] + b[x.second + 1];
        ++ x.second;
        q.push(x);
    }
    return res;
}

int main(void)
{
    vector<int> a{1,2,3}, b{1,2,2};
    auto res = TopNSum(a, b);
    for(auto x : res) 
        cout << x << " ";
    cout << endl;
    return 0;
}
