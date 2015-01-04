/**
 * @file convert.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void dfs(int cur, string &path, const string &str)
{
    if(cur == str.size()) {
        cout << path << endl;
        return;
    }
    path += str[cur] -  '1' + 'a';
    dfs(cur+1, path, str);
    path.pop_back();
    
    if(cur+1 < str.size()) {
        int num = atoi(str.substr(cur, 2).c_str());
        if(num <= 26) {
            path += 'a' + num-1;
            dfs(cur+2, path, str);
            path.pop_back();
        }
    }
}

void Convert(const string &str)
{
    string path;
    dfs(0, path, str);
}

int main(void)
{
    Convert("12259");
    return 0;
}
