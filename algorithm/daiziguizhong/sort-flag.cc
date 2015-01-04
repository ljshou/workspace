/**
 * @file sort-flag.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    if(begin == end) return; 
    auto i = begin, j = begin, k = end - 1;
    while(j <= k) {
        if(*j == 0) {
            iter_swap(i++, j++);
        }
        else if(*j == 2) {
            iter_swap(k--, j);
        }
        else {
            ++j;
        }
    }
    copy(begin, end, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(void)
{
    vector<int> vec{1,1,0,1,2,2,1,0};
    Sort(vec.begin(), vec.end());
    return 0;
}
