/**
 * @file subset2.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-30
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * incremental scheme
 * build f[i] based on f[i-1]
 */
vector<vector<int> > SubsetDup(vector<int> &S)
{
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    res.push_back(vector<int>());

    int i(0), j(0);
    while(i < S.size()) {
        while(j < S.size() && S[j] == S[i]) ++j;

        int size = res.size();
        for(int k=0; k<size; ++k) {
            for(int l=1; l<=j-i; ++l) {
                res.push_back(res[k]);
                for(int m=0; m<l; ++m) {
                    res.back().push_back(S[i]);
                }
            }
        }

        i = j;
    }
    return res;
}

void Test()
{
    vector<int> S{1, 2, 2};
    auto res = SubsetDup(S);
    for(auto vec : res) {
        for(auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    Test();
    return 0;
}
