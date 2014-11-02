#include <bits/stdc++.h>
using namespace std;

void dfs(const string s, const int i, const vector<vector<int> > &parent, string &cur , vector<string> &ret, long long &max_number)
{
    if(parent[i].empty()) return;
    if(parent[i].size() == 1 && parent[i][0] == -1)
    {
        if(atoi(cur.c_str()) > max_number)
            max_number = atoi(cur.c_str());
        ret.push_back(cur);
        return;
    }

    string temp = cur;
    for(int k = 0 ; k < parent[i].size(); ++k)
    {
        cur = s[parent[i][k]] + cur;
        dfs(s,parent[i][k],parent,cur,ret,max_number);
        cur = temp;
    }
}
vector<string> longSubStr(const string s)
{
    if(s.empty()) return vector<string>();
    int n = s.size();
    //each element at least is 1
    vector<int> f(n,1);
    vector<vector<int> > parent(n,vector<int>());
    parent[0].push_back(-1);
    f[0] = 1;
    vector<int> prev;

    for(int i = 1 ; i < n; ++i)
    {
        prev.clear();
        for(int k = 0; k < i ; ++k)
        {
            if(s[k] < s[i])
            {
                if(f[k] + 1 > f[i])
                {
                    f[i] = max(f[k]+1, f[i]);
                }
            }
        }
        for(int j = 0 ; j < i ; ++j)
        {
            if(f[i] == f[j] + 1)
            {
                parent[i].push_back(j);
            }
        }
        if(parent[i].empty())
        {
            parent[i].push_back(-1);
        }
    }

    for(int i = 0 ; i < n ; ++i)
    {
        cout << f[i] << " : ";
        if(parent[i].empty()) {cout << endl; continue;}
        for(int j = 0 ; j < parent[i].size(); ++j)
            cout << parent[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    int max_len = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        max_len = max(max_len, f[i]);
    }
    vector<string> ret;
    string cur;
    long long max_number = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        if(f[i] == max_len)
        {
            cout << "dfs " << i << endl;
            cur.clear();
            cur += s[i];
            dfs(s,i,parent,cur,ret, max_number);
        }
    }
    cout << "max_number : " << max_number << endl;
    return ret;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ret = longSubStr(s);
    sort(ret.begin(), ret.end());
    for(int i = 0 ; i< ret.size(); ++i)
        cout << ret[i] << endl;

    return 0;
}
