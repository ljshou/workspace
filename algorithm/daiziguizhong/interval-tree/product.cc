/**
 * @file product.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
#define L(x) (((x)<<1)+1)
#define R(x) (((x)<<1)+2)
const int MAX_N = 1e5 + 10;
struct Node {
    int left, right;
    int flag, val;
};
int A[MAX_N];
Node node[MAX_N * 4];

void Build(int t, int l, int r)
{
    node[t].left = l;
    node[t].right = r;
    node[t].flag = 0;
    if(l == r) {
        node[t].val = A[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(L(t), l, mid);
    Build(R(t), mid+1, r);
    node[t].val = node[L(t)].val + node[R(t)].val;
}

void Modify(int t, int begin, int end, int val)
{
    if(node[t].left == begin && node[t].right == end) {
        node[t].flag = val;
        node[t].val = (end - begin + 1) * val;
        return;
    }
    if(node[t].flag) {
        node[L(t)].flag = node[t].flag;
        node[R(t)].flag = node[t].flag;
        node[L(t)].val = node[t].flag * (node[L(t)].right - node[L(t)].left + 1);
        node[R(t)].val = node[t].flag * (node[R(t)].right - node[R(t)].left + 1);
        node[t].flag = 0;
    }
    int mid = (node[t].left + node[t].right) / 2;
    if(begin > mid) {
        Modify(R(t), begin, end, val);
    }
    else if(end <= mid) {
        Modify(L(t), begin, end, val);
    }
    else {
        Modify(L(t), begin, mid, val);
        Modify(R(t), mid+1, end, val);
    }
    node[t].val = node[L(t)].val + node[R(t)].val;
}

long Query(int t, int begin, int end)
{
    if(node[t].left == begin && node[t].right == end) {
        return node[t].val;
    }
    if(node[t].flag) {
        node[L(t)].flag = node[t].flag;
        node[R(t)].flag = node[t].flag;
        node[L(t)].val = node[t].flag * (node[L(t)].right - node[L(t)].left + 1);
        node[R(t)].val = node[t].flag * (node[R(t)].right - node[R(t)].left + 1);
        node[t].flag = 0;
    }
    int mid = (node[t].left + node[t].right) / 2;
    if(begin > mid) {
        return Query(R(t), begin, end);
    }
    else if(end <= mid) {
        return Query(L(t), begin, end);
    }
    else {
        return Query(L(t), begin, mid) + 
               Query(R(t), mid+1, end);
    }
}

int main(void)
{
    int N, E;
    int flag, l, r, val;
    cin >> N;
    For(i, N) cin >> A[i+1];
    Build(1, 1, N);

    cin >> E;
    For(i, E) {
        cin >> flag >> l >> r;
        if(flag) {
            cin >> val;
            Modify(1, l, r, val);
        }
        else {
            cout << Query(1, l, r) << endl;
        }
    }
    return 0;
}
