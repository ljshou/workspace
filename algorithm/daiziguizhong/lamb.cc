#include<iostream>
#include<cassert>
using namespace std;
#define n 8 

bool initial[n]; 

struct Node
{
    int l,r;
    int sum;
}node[3*n];

void buildTree(int l, int r, int index){
    node[index].l = l;
    node[index].r = r;
    node[index].sum = 0;
    if(l != r)
    {
        buildTree(l, (l+r)/2, 2*index);
        buildTree((l+r)/2+1, r, 2*index+1);
    }
}

void insert(int begin, int end, int l, int r, int index)
{
    if(begin == l && end == r)
    {
        cout << "l, r " << l << " " << r << endl;
        node[index].sum++;
        return;
    }
    int mid = (l+r)/2;
    if(end <= mid) insert(begin, end, l, mid, index*2);
    else if(begin > mid) insert(begin, end, mid+1, r, index*2+1);
    else
    {
        insert(begin, mid, l, mid, index*2);
        insert(mid+1, end, mid+1, r, index*2+1);
    }
}

void Round(int begin, int end)
{
    insert(begin, end, 1, n, 1);
}

int search(int l, int r, int m, int ans, int index)
{
    ans += node[index].sum;
    if(l == r) return ans;
    int mid = (l + r)/2;
    if(m <= mid) ans += search(l, mid, m, 0, index*2);
    else ans += search(mid+1, r, m, 0, index*2+1);
    return ans;
}

bool query(int m)
{
    int filpNum = search(1, n, m, 0, 1);
    if(filpNum % 2 == 0) return initial[m-1];
    return !initial[m-1];
}

int main()
{
    buildTree(1,n,1);
    /*
    Round(1,5);
    Round(2,6);
    Round(4,8);
    assert(query(1) == true);
    assert(query(2) == false);
    assert(query(3) == false);
    assert(query(4) == true);
    assert(query(5) == true);
    assert(query(6) == false);
    assert(query(7) == true);
    assert(query(8) == true);
    assert(query(10) == false);
    */
    Round(4, 6);
    assert(query(4) == true);
    //for(int i = 1;i<9;i++) printf("%d", search(1, n, i, 0, 1));
    return 0;
}
