/**
 * @file rmq.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-02
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
#define L(x) (((x)<<1)+1)
#define R(x) (((x)<<1)+2)
const int MAX_N = 1e6 + 10;
struct Node {
    int left, right;
    int min_val;
};
Node node[MAX_N << 2];
int A[MAX_N];
int N;

void Build(int t, int l, int r)
{
    node[t].left = l;
    node[t].right = r;
    if(l == r) {
        node[t].min_val = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(L(t), l, mid);
    Build(R(t), mid+1, r);
    node[t].min_val = min(node[L(t)].min_val, node[R(t)].min_val);
}

void Modify(int t, int index, int val)
{
    if(node[t].left == index && node[t].right == index) {
        node[t].min_val = val;
        return;
    }
    int mid = (node[t].left + node[t].right) >> 1;
    if(index <= mid) {
        Modify(L(t), index, val);
    }
    else {
        Modify(R(t), index, val);
    }
    node[t].min_val = min(node[L(t)].min_val, node[R(t)].min_val);
}

int Query(int t, int begin, int end)
{
    if(begin > node[t].right || end < node[t].left) {
        return INT_MAX;
    }
    if(begin <= node[t].left && end >= node[t].right) {
        return node[t].min_val;
    }
    int mid = (node[t].left + node[t].right) >> 1;
    return min(Query(L(t), begin, end), Query(R(t), begin, end));
}

int main(void)
{
    int E, flag, a, b;
    cin >> N;
    For(i, N) cin >> A[i+1];
    Build(1, 1, N);
    cin >> E;
    For(i, E) {
        cin >> flag >> a >> b;
        if(flag == 0) {
            cout << Query(1, a, b) << endl;
        }
        else {
            Modify(1, a, b);
        }
    }
    return 0;
}
