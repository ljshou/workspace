/**
 * @file two-heap.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-26
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

class Median {
public:
    Median(const vector<int> &vec) {
        for(auto x : vec) {
            Insert(x);
        }
    }
    void Insert(int x);
    double GetMedian() const {
        if(left.size() < right.size()) {
            return right.top();
        }
        else if(left.size() > right.size()) {
            return left.top();
        }
        else {
            if(left.empty()) throw runtime_error("empty");
            return (left.top() + right.top()) / 2.0;
        }
    }
private:
    priority_queue<int, vector<int>, less<int> > left; //max heap 
    priority_queue<int, vector<int>, greater<int> > right;//min heap
};

void Median::Insert(int x) 
{
    if(left.size() == right.size()) {
        if(left.empty()) {
            left.push(x);
        }
        else {
            if(x <= right.top()) left.push(x);
            else right.push(x);
        }
    }
    else if(left.size() < right.size()) {
        if(x <= right.top()) {
            left.push(x);
        }
        else {
            left.push(right.top()); right.pop();
            right.push(x);
        }
    }
    else {
        if(x < left.top()) {
            right.push(left.top()); left.pop();
            left.push(x);
        }
        else {
            right.push(x);
        }
    }
}

void Test()
{
    vector<int> vec{1,2,3};
    Median m(vec);
    assert(m.GetMedian() == 2);
    m.Insert(4);
    assert(m.GetMedian() == 2.5);
    m.Insert(5);
    assert(m.GetMedian() == 3);
    m.Insert(6);
    assert(m.GetMedian() == 3.5);
}

int main(void)
{
    Test();
    return 0;
}
