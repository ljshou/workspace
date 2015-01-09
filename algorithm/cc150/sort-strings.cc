/**
 * @file sort-strings.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-06
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Cmp : public binary_function<string, string, bool>
{
    bool operator()(string lhs, string rhs) const {
        sort(lhs.begin(), lhs.end());
        sort(rhs.begin(), rhs.end());
        return lhs < rhs;
    }
};

void Sort(vector<string> &vec)
{
    sort(vec.begin(), vec.end(), Cmp());
}

int main(void)
{
    vector<string> vec{"azc", "zca", "a", "caz", "b", "ab"};
    Sort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    return 0;
}
