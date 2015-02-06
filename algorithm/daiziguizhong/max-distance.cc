/**
 * @file max-distance.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * O(N)
 */ 
int MaxDistance(const vector<int> &vec)
{
    stack<int> s;
    for(int i=0; i<vec.size(); ++i) {
        if(s.empty() || vec[s.top()] > vec[i])
            s.push(i);
    }
    int dist = 0;
    for(int i=(int)vec.size()-1; i>=0; --i) {
        while(!s.empty() && vec[s.top()] < vec[i]) {
            dist = max(dist, i - s.top());
            s.pop();
        }
    }
    cout << dist << endl;
    return dist;
}

int MaxDistance2(const vector<int> &vec)
{
    if(vec.empty()) return 0;
    const int n = vec.size();
    vector<int> LMin(n, vec[0]);
    for(int i=1; i<n; ++i) LMin[i] = min(LMin[i-1], vec[i]);
    vector<int> RMax(n, vec[n-1]);
    for(int i=n-2; i>=0; --i) RMax[i] = max(RMax[i+1], vec[i]);

    int dist = 0;
    int i(0), j(0);
    while(i < n && j < n) {
        if(LMin[i] < RMax[j]) {
            dist = max(dist, j-i);
            ++j;
        }
        else {
            ++i;
        }
    }
    cout << dist << endl;
    return dist;
}

int MaxDistance3(const vector<int> &vec)
{ 
    //todo
    //deal with duplicates
    if(vec.empty()) return 0;
    const int n = vec.size();
    vector<int> index(n);
    for(int i=0; i<n; ++i) index[i] = i;
    sort(index.begin(), index.end(), [&](const int i, const int j) {
            return vec[i] < vec[j];});

    int dist = 0;
    vector<int> right(n);
    right[n-1] = index[n-1];
    for(int i=n-2; i>=0; --i) right[i] = max(right[i+1], index[i]);

    for(int i=0; i<n; ++i)
        dist = max(dist, right[i] - index[i]);

    cout << dist << endl;
    return dist;
}


void Test()
{
    vector<int> vec(20);
    srand(time(0));
    for(int i=0; i<100; ++i) {
        generate(vec.begin(), vec.end(), []() {return rand() % 10; });
        assert(MaxDistance(vec) == MaxDistance2(vec));
    }
}

int main(void)
{
    Test();
    return 0;
}
