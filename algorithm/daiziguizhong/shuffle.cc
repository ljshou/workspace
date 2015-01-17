/**
 * @file shuffle.cc
 * @brief shuffle
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <iostream>
#include <vector>
using namespace std;

template<class InputIterator>
void Shuffle(InputIterator first, InputIterator last)
{
    if(first == last) return;
    for(InputIterator i = first+1; i != last; ++i) {
        iter_swap(i, first + rand() % ((i - first) + 1));
    }
}

void Test()
{
    vector<int> vec{1,2,3,4,5};
    Shuffle(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
