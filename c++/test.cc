/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.com
 * @version 0.1.00
 * @date 2014-12-12
 */

#include <iostream>
#include <vector>
using namespace std;

void ChangeItem(vector<int> &vec)
{
    vec[1] = 100;
}

int main(void)
{
    vector<int> vec{0, 1, 2};
    ChangeItem(vec);
    cout << vec[1] << endl;

    vector<vector<int> > vec2(1, vector<int>(2, 0));
    ChangeItem(vec2[0]);
    cout << vec2[0][1] << endl;

    vector<vector<vector<int> > > vec3(1, vector<vector<int> >(2, vector<int>(2, 0)));
    ChangeItem(vec3[0][0]);
    cout << vec3[0][0][1] << endl;
    return 0;
}
