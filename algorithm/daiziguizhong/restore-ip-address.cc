/**
 * @file restore-ip-address.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-29
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        vector<string> res;
        dfs(0, 4, s, path, res);
        return res;
    }
private:
    void dfs(int cur, int count, const string &s, string &path, vector<string> &res)
    {
        if(s.size()-cur < count || s.size()-cur > 3*count) 
            return;

        if(cur == s.size()) {
            if(count == 0)
                res.push_back(string(path.begin(), path.end()-1));
            return;
        }

        for(int i=1; i<=3 && cur+i<=s.size(); ++i) {
            if(atoi(s.substr(cur, i).c_str()) < 256) {
                path += s.substr(cur, i) + '.';
                cout << "cur: " << cur << endl;
                cout << path << endl;
                dfs(cur+i, count-1, s, path, res);
                path.erase(path.end()-i-1, path.end());
            }
        }
    }
};

int main(void)
{
    Solution s;
    auto vec = s.restoreIpAddresses("0000");
    for(auto str : vec) 
        cout << str << endl;
    
    return 0;
}
