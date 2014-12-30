/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> a{1,2,3}, b{2,2,2};
    a.insert(a.end(), 10, 1);
    a.insert(a.end(), b.begin(), b.end());
    a.assign(b.begin(), b.end());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
