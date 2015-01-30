/**
 * @file interval-tree.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Lantern
{
public:
    Lantern(int n=0):N(n) {
        node.resize(3*N, 0);
    }
    void Round(int begin, int end) {
        insert(begin, end, 1, N, 1);
    }
    int Query(int m) {
        int sum = search(1, N, m, 1);
        return (sum & 0x1);
    }
private:
    int N;
    vector<int> node;
    void insert(int begin, int end, int l, int r, int index);
    int search(int l, int r, int m, int index); 
};

void Lantern::insert(int begin, int end, int l, int r, int index) 
{
    if(end < l || begin > r) 
        return; //not intersected
    if(begin <= l && end >= r) {
        ++node[index];
        return;
    }
    int mid = (l+r)/2;
    insert(begin, end, l, mid, 2*index);
    insert(begin, end, mid+1, r, 2*index+1);
}

int Lantern::search(int l, int r, int m, int index)
{
    if(m < l || m > r) return 0;
    int sum = node[index];
    if(l == r) return sum; //leaf

    int mid = (l+r)/2;
    if(m <= mid) {
        sum += search(l, mid, m, 2*index);
    }
    else {
        sum += search(mid+1, r, m, 2*index+1);
    }
    return sum;
}
int main()
{
    Lantern l(8);
    l.Round(1,5);
    l.Round(2,6);
    l.Round(4,8);
    assert(l.Query(1) == true);
    assert(l.Query(2) == false);
    assert(l.Query(3) == false);
    assert(l.Query(4) == true);
    assert(l.Query(5) == true);
    assert(l.Query(6) == false);
    assert(l.Query(7) == true);
    assert(l.Query(8) == true);
    assert(l.Query(10) == false);
    return 0;
}
