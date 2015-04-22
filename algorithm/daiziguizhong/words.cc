/**
 * @file words.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */
#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
struct Trie{
    bool isEnd;
    Trie *children[26];  
    Trie(): isEnd(false) {
        fill_n(children, 26, nullptr);
    }
};

void insert(Trie *root, const string &str) {
    for(auto c : str) {
        if(!isupper(c)) return;
        auto child = root->children[c - 'A'];
        if(child == nullptr) {
            child = root->children[c-'A'] = new Trie();
        }
        root = child;
    }
    root->isEnd = true;
}

bool dfs(int row, int col, Trie *root, 
         vector<vector<char> > &grid)
{
    if(root && root->isEnd) return true;

    const int m = grid.size(), n = grid.front().size();
    if(row < 0 || row >= m || col < 0 || col >= n)
        return false;
    if(grid[row][col] == '#') return false;
    char tmp = grid[row][col];

    if(root->children[tmp - 'A'] == nullptr) return false;
    root = root->children[tmp - 'A'];

    grid[row][col] = '#';

    bool res = dfs(row-1, col, root, grid) 
        ||  dfs(row+1, col, root, grid) 
        ||  dfs(row, col-1, root, grid) 
        ||  dfs(row, col+1, root, grid);

    grid[row][col] = tmp;

    return res;
}

bool exists(vector<vector<char> > &grid, vector<string> &patterns) {
    if(grid.empty() || grid.front().empty()) return false;
    if(patterns.empty()) return true;
    Trie *root = new Trie();
    for(auto s : patterns) 
        insert(root, s);

    const int m = grid.size(), n = grid.front().size();
    For(i, m) {
        For(j, n)  {
            if(dfs(i, j, root, grid))
                return true;
        }
    }
    return false;
}

int main(void)
{
    vector<vector<char> > grid{{'D'}};
    vector<string> patterns{"D"};
    cout << exists(grid, patterns) << endl;
    return 0;
}
