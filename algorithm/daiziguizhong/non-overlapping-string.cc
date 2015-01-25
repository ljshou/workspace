/**
 * @file non-overlapping-string.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-25
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hashString(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        n |= (1 << (s[i] - 'a'));
    }
    return n;
}

int maxProduct(const vector<string> & dict) 
{
    vector<int> dp((1 << 26), 0);
    for(auto str : dict) {
        int hash = hashString(str);
        dp[hash] = max(dp[hash], int(str.size()));
    }
    int n = (1 << 26);
    for(int i = 3; i < n; ++i) {
        int flag = 1;
        for(int j = 0; j < 26; ++j) {
            if(i&flag) {
                dp[i] = max(dp[i], dp[i^flag]);
            }
            flag <<= 1;
        }
    }
    int result = 0;
    int mask = 0x03FFFFFF;
    for (int i = 1; i < n; ++i) {
        result = max(result, dp[i]*dp[(~i) & mask]);
    }
    return result;
}

void Test()
{
    vector<string> vec{"ab", "bcd", "zz"};
    cout << maxProduct(vec) << endl;
}

int main(void)
{
    Test();
    return 0;
}
