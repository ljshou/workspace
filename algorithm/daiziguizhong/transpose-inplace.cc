/**
 * @file transpose-inplace.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-05
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void Transpose(int *A, int r, int c)
{
    assert(A != nullptr);
    int size  =  r*c - 1;
    vector<bool> flag(size+1, false);
    flag[0] = flag[size] = true; //first and last elements not move
    for(int i=1; i<size; ++i) {
        if(flag[i]) continue;
        int begin = i;
        int next = i;
        int t = A[i];
        do {
            next = i * r % size;
            swap(t, A[next]);
            flag[i] = true;
            i = next;
        }while(i != begin);
    }
}

void Print2DMatrix(int *A, int r, int c)
{
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            cout << A[i*c + j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int a[] = {1,2,3,4,5,6};
    Print2DMatrix(a, 2, 3);
    Transpose(a, 2, 3);
    Print2DMatrix(a, 3, 2);
    return 0;
}
