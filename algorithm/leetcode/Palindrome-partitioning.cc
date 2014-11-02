class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;
        const int n = s.size();
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for(int i=0; i<n; ++i) g[i][i] = true;
        
        for(int i=n-2; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                if(s[i] == s[j] && (j-i<2 || g[i+1][j-1])) {
                    g[i][j] = true;
                }
            }
        }
        vector<string> path;
        genPath(0, path, s, g, res);
        return res;
    }
private:
    void genPath(int cur, vector<string> &path, string s, vector<vector<bool>> &g, vector<vector<string>> &res) {
        if(cur == s.size()) {
            //exit
            res.push_back(path);
            return;
        }
        for(int i=cur; i<s.size(); ++i) {
            if(!g[cur][i]) continue;
            path.push_back(s.substr(cur, i-cur+1));
            genPath(i+1, path, s, g, res);
            path.pop_back();
        }
    }
};
