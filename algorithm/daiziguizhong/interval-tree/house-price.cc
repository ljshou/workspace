/**
 * @file house-price.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
#define L(x) (((x)<<1) + 1)
#define R(x) (((x)<<1) + 2)
struct Node {
    int val, flag0, flag1;   
    int left, right;
};
const int MAX_N = 1e5 + 10;
int A[MAX_N];
Node node[MAX_N * 4]; //*4防止越界 

void Build(int l, int r, int index)
{
    node[index].left = l;
    node[index].right= r;
    node[index].flag0 = node[index].flag1 = 0;
    if(l == r) {
        node[index].val = A[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(l, mid, L(index));
    Build(mid+1, r, R(index));
    node[index].val = node[L(index)].val + node[R(index)].val;
}

void Query(int t, int begin, int end, int val, int flag)
{
    if(end < node[t].left || begin > node[t].right) 
        return;

    if(begin <= node[t].left && end >= node[t].right) {
        if(flag == 0) {
            node[t].flag0 += val;
            node[t].val += val * (node[t].right - node[t].left + 1);
        }
        else {
            node[t].flag0 = 0;
            node[t].flag1 = val;
            node[t].val = val * (node[t].right - node[t].left + 1);
        }
        return;
    }

    if(node[t].flag1) {
        node[L(t)].flag1 = node[t].flag1;    
        node[R(t)].flag1 = node[t].flag1;    
        node[L(t)].val = node[t].flag1 * (node[L(t)].right - node[L(t)].left + 1);
        node[R(t)].val = node[t].flag1 * (node[R(t)].right - node[R(t)].left + 1);
        node[t].flag1 = 0;
        node[L(t)].flag0 = 0;
        node[R(t)].flag0 = 0;
    }
    if(node[t].flag0) {
        node[L(t)].flag0 += node[t].flag0;
        node[R(t)].flag0 += node[t].flag0;
        node[L(t)].val += node[t].flag0 * (node[L(t)].right - node[L(t)].left + 1);
        node[R(t)].val += node[t].flag0 * (node[R(t)].right - node[R(t)].left + 1);
        node[t].flag0 = 0;
    }

    Query(L(t), begin, end, val, flag);    
    Query(R(t), begin, end, val, flag);    
    node[t].val = node[L(t)].val + node[R(t)].val;
}

int main(void)
{
    int V, E;
    int flag, begin, end, val;
    cin >> V >> E;
    For(i, V+1) cin >> A[i];
    Build(0, V, 0);

    For(i, E) {
        cin >> flag >> begin >> end >> val;
        Query(0, begin, end, val, flag);
        cout << node[0].val << endl;
    }
    return 0;
}
