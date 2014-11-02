class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size()+1, false);
        f[0] = true;
        for(int i=1; i<f.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(dict.find(s.substr(j, i-j)) != dict.end() && f[j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};
