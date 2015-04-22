/**
 * @file bi-parte.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-02-15
 */

#include <bits/stdc++.h>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)

const int Max_N = 1e4 + 5;
int N, M;
vector<int> G[Max_N];
int color[Max_N];

bool dfs(int u, int c)
{
    color[u] = c;
    for(auto v : G[u]) {
        if(color[v] == c) return false;
        if(color[v] == 0 && !dfs(v, -1*c)) return false;
    }
    return true;
}

bool IsBiparte()
{
    For(u, N) {
        if(color[u] == 0) {
            if(dfs(u, 1) == false) return false;
        }
    }
    return true;
}

int main(void)
{
    int t, u, v;
    cin >> t;
    For(i, t) {
        cin >> N >> M;
        fill_n(color, N, 0);
        For(i, N) G[i].clear();

        For(i, M) {
            cin >> u >> v;
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(IsBiparte()) cout << "Correct" << endl;
        else cout << "Wrong" << endl;
    }
    return 0;
}
