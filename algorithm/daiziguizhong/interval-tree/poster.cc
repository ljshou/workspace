/**
 * @file poster.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-02
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
#define L(x) (((x)<<1) + 1)
#define R(x) (((x)<<1) + 2)
struct Node {
    int left, right;
    int mark;
};
const int MAX_N = 1e5 + 10;
int a[MAX_N];
int b[MAX_N];
Node node[MAX_N << 2];
int N; //range size if [1 : N]

void Down(int t)
{
    if(node[t].mark) {
        node[L(t)].mark = node[R(t)].mark = node[t].mark;
        node[t].mark = 0;
    }
}

void Build(int t, int l, int r)
{
    node[t].left = l; node[t].right = r;
    node[t].mark = 0;
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    Build(L(t), l, mid);
    Build(R(t), mid+1, r);
}

void Update(int t, int begin, int end, int mark)
{
    if(begin <= node[t].left && end >= node[t].right) {
        node[t].mark = mark;
        return;
    }
    Down(t);
    int mid = (node[t].left + node[t].right) >> 1;
    if(begin > mid) {
        Update(R(t), begin, end, mark);
    }
    else if(end <= mid) {
        Update(L(t), begin, end, mark);
    }
    else {
        Update(L(t), begin, mid, mark);
        Update(R(t), mid+1, end, mark);
    }
}

int Query(int t, int index)
{
    if(node[t].left == node[t].right) {
        return node[t].mark; //leaf node
    }
    Down(t);
    int mid = (node[t].left + node[t].right) >> 1;
    if(index <= mid) {
        return Query(L(t), index);
    }
    else {
        return Query(R(t), index);
    }
}

int main(void)
{
    int E;
    cin >> E >> N;
    For(i, E) {
        cin >> a[i] >> b[i];
    }
    //离散化
    vector<int> all;
    all.reserve(2*E);
    For(i, E) {
        all.push_back(a[i]);
        all.push_back(b[i]);
    }
    sort(all.begin(), all.end()); 
    all.erase(unique(all.begin(), all.end()), all.end());
    N = all.size() - 1;

    Build(1, 1, N);

    For(i, E) {
        a[i] = (lower_bound(all.begin(), all.end(), a[i])) - all.begin();
        b[i] = (lower_bound(all.begin(), all.end(), b[i])) - all.begin();
        //cout << a[i] << " " << b[i] << endl;
        Update(1, a[i]+1, b[i], i+1);
    }
    set<int> s;
    for(int i=1; i<=N; ++i) 
        s.insert(Query(1, i));
    cout << s.size() - (s.find(0) == s.end() ? 0 : 1) << endl;

    return 0;
}
