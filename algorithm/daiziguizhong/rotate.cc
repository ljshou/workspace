/**
 * @file rotate.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-26
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * forward only iterator
 */
template<class ForwardIterator>
void Rotate(ForwardIterator first, ForwardIterator mid,
            ForwardIterator last)
{
    for(ForwardIterator i = mid; ; ) {
        iter_swap(first, i);
        ++first, ++i;
        if(first == mid) {
            if(i == last) return;
            mid = i;
        }
        else if(i == last) {
            i = mid;
        }
    }
}

void Test()
{
    vector<int> vec{1,2,3,4,5};
    Rotate(vec.begin(), vec.begin() + 3, vec.end());
    for(auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
