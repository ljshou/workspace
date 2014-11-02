class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if(s.empty() || dict.empty()) return res;
        vector<bool> f(s.size()+1, false);
        f[0] = true;
        vector<vector<bool> > prev(s.size()+1, vector<bool>(s.size(), false));
        for(int i=1; i<=s.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(f[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    f[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> path;
        genPath(s.size(), path, s, prev, res);
        return res;
    }
private:
    void genPath(int cur, vector<string> &path, string &s, vector<vector<bool>> &prev, vector<string> &res)
    {
        if(cur == 0) {
            string tmp;
            for(auto it=path.rbegin(); it!=path.rend(); ++it) {
                tmp += *it + ' ';
            }
            tmp.erase(tmp.end()-1);
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<s.size(); ++i) {
            if(prev[cur][i]) {
                path.push_back(s.substr(i, cur-i));
                genPath(i, path, s, prev, res);
                path.pop_back();
            }
        }
        
    }
};
