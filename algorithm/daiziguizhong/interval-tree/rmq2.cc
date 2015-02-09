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
    t += N-1;
    node[t].min_val = A[index];
    t = (t - 1) >> 1;
    while(t > 0) {
        node[t].min_val = min(node[L(t)].min_val, node[R(t)].min_val);
        t = (t - 1) >> 1;
    }
}

int Query(int t, int begin, int end)
{
    if(node[t].left == begin && node[t].right == end) {
        return node[t].min_val;
    }
    int mid = (node[t].left + node[t].right) >> 1;
    if(begin > mid) {
        return Query(R(t), begin, end);
    }
    else if(end <= mid) {
        return Query(L(t), begin, end);
    }
    else {
        return min(Query(L(t), begin, mid), Query(R(t), mid+1, end));
    }
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
