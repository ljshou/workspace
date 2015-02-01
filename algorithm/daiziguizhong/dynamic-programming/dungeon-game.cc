/**
 * @file dungeon-game.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-10
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &a) {
    if(a.empty() || a.front().empty()) return 0;
    int m = a.size(), n = a.front().size(); 
    vector<vector<int> > f(m+1, vector<int>(n+1, INT_MAX));
    f[m][n-1] = f[m-1][n] = 0;
    for(int i=m-1; i>=0; --i) {
        for(int j=n-1; j>=0; --j) {
            f[i][j] = max(0, min(f[i+1][j], f[i][j+1]) - a[i][j]);
        }
    }
    cout << f[0][0] + 1 << endl;
    return f[0][0] + 1;
}

void Test() {
    vector<vector<int> > b{{0,0,0},{-1,0,0},{2,0,-2}};
    assert(calculateMinimumHP(b) == 2);

    vector<vector<int> > a{{19,14,-25,-20,-36},
        {-46,-72,-74,25,-24},
        {-38,-57,-38,-73,-23},
        {-12,1,-70,44,-98}};
    assert(calculateMinimumHP(a) == 115);
}

int main(void)
{
    Test();
    return 0;
}
