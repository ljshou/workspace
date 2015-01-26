/**
 * @file min-longest-dist.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-26
 */

#include <iostream>
#include <queue>
using namespace std;

struct Elem {
    int index;
    int data;
    Elem(int index_=0, int data_=0):
        index(index_), data(data_) {}

    bool operator<(const Elem &rhs) const {
        return data < rhs.data;
    }
};

int MinDistance(const vector<int> &vec, int m)
{
    if(vec.size() < m) return -1;
    priority_queue<Elem> q;
    for(int i=0; i<m; ++i) 
        q.push(Elem(i, vec[i]));

    int dist = q.top().data;
    for(int i=m; i<vec.size(); ++i) {
        while(q.top().index <= i - m) q.pop(); //obslete
        q.push(Elem(i, vec[i]));
        dist = min(dist, q.top().data);
    }
    return dist;
}

void Test() 
{
    vector<int> vec{1,3,4,4,5,1};
    cout << MinDistance(vec, 3) << endl;
}

int main(void)
{
    Test();
    return 0;
}
