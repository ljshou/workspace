/**
 * @file shedule.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef int JobID;


bool dfs(int u, vector<int> &visited,
         const map<JobID, vector<JobID> > &deps,
         vector<JobID> &result, int &count)
{
    visited[u] = 1;
    auto it = deps.find(u);
    if(it != deps.end()) {
        for(auto v : it->second) {
            if(visited[v] == 0) {
                if(!dfs(v, visited, deps, result, count))
                    return false;
            }
            else if(visited[v] == 1) {
                return false;
            }
        }
    }
    visited[u] = 2;
    result[count++] = u;
    return true;
}
/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                 vector<JobID> &result) {
    if(n <= 0) return true;
    vector<int> visited(n+1, 0);
    //0 unvisited, 1 visiting, 2 visited
    int count = 0;
    for(int i=1; i<=n; ++i) {
        if(!visited[i]) {
            if(!dfs(i, visited, deps, result, count))
                return false;
        }
    }
    return true;
}

int main(void)
{
    map<JobID, vector<JobID> > deps;
    vector<JobID> result(2);
    jobSchedule(deps, 2, result);
    for(auto x : result) 
        cout << x << " ";
    cout << endl;
    return 0;
}
