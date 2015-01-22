/**
 * @file perfect-shuffle.cc
 * @brief a1a2a3...anb1b2...bn -> a1b1a2b2....anbn
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-22
 */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

/**
 * inplace transpose matrix r*c to c*r
 */
void Transpose(string &str, int r, int c)
{
    if(str.size() != r*c || r <= 0 || c <= 0)
        return;
    if(r == 1 || c == 1) 
        return;
    int size = r*c - 1;
    vector<bool> visited(size+1, false);
    visited[0] = visited[size] = true;
    
    for(int i=1; i<size; ++i) {
        if(visited[i]) continue;
        int begin = i;
        auto tmp = str[i];
        int next = i;
        do {
            next = i*r % size;
            swap(tmp, str[next]);
            visited[i] = true;
            i = next;
        }while(i != begin);
    }
}

void PerfectShuffle(string str)
{
    assert((str.size() & 0x1) == 0);
    int n = str.size() / 2;
    Transpose(str, 2, n);
    cout << str << endl;
}

void Test()
{
    PerfectShuffle("123456");
}

int main(void)
{
    Test();
    return 0;
}
