/**
 * @file min-range.cc
 * @brief n sorted arrays, find a minimum range that 
 * in every array, there exists at least one element.
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct Element
{
    int val, row, col;
    Element(int v=0, int r=0, int c=0):
        val(v), row(r), col(c) {}
};
//min heap
/*
bool operator<(const Element &lhs, const Element &rhs) {
    return lhs.val > rhs.val;
}
*/
struct cmp: public binary_function<Element, Element, bool>
{
    bool operator() (const Element &lhs, const Element &rhs) const {
        return lhs.val > rhs.val;
    }
};

pair<int, int> MinRange(const vector<vector<int> > &vec)
{
    if(vec.empty()) return make_pair(0, 0);
    int left(0), right(0), len(INT_MAX);

    //push first col into priority_queue
    priority_queue<Element, vector<Element>, cmp> q;
    int largest = INT_MIN;
    for(int i=0; i<vec.size(); ++i) {
        if(vec[i].empty()) continue;
        largest = max(largest, vec[i][0]);
        q.push(Element(vec[i][0], i, 0));
    }

    //push elements in increasing order
    while(true) {
        int smallest = q.top().val;
        if(largest - smallest + 1 < len) {
            left = smallest;
            right = largest;
            len = largest - smallest + 1;
        }

        auto x = q.top(); q.pop();
        int i = x.row, j = x.col;
        if(j >= vec[i].size()) break;
        q.push(Element(vec[i][j+1], i, j+1));
        largest = max(largest, vec[i][j+1]);
    }
    return make_pair(left, right);
}

int main(void)
{
    vector<vector<int> > vec{{1,2,3,3,4,6}, {1000}};
    auto range = MinRange(vec);
    cout << range.first << " " << range.second << endl;
    return 0;
}
