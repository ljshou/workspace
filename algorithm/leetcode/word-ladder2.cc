class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        unordered_map<string, vector<string> > father;
        unordered_set<string> cur, next, visited;
        bool found(false);
        
        cur.insert(start);
        while(!cur.empty()) {
            for(auto x : cur) 
                visited.insert(x);
            for(auto word : cur) {
                string new_word = word;
                for(int i=0; i<word.size(); ++i) {
                    for(char c='a'; c<='z'; ++c) {
                        if(c == word[i]) continue;
                        new_word[i] = c;
                        if(end == new_word) {
                            found = true;
                            father[new_word].push_back(word);
                        }
                        else if(visited.find(new_word)==visited.end() && dict.find(new_word) != dict.end()) {
                            father[new_word].push_back(word);
                            next.insert(new_word);
                        }
                    }
                    new_word[i] = word[i];
                }
            }
            cur.clear();
            if(found == false) {
                cur.swap(next);
            }
        }
        if(found) {
            vector<string> path;
            genPath(end, path, start, father, res);
        }
        return res;
    }
private:
    void genPath(string cur, vector<string> &path, string &start, unordered_map<string, vector<string> > &father, vector<vector<string>> &res) {
        if(cur == start) {
            vector<string> temp = path;
            temp.push_back(start);
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        path.push_back(cur);
        for(auto word : father[cur]) {
            genPath(word, path, start, father, res);
        }
        path.pop_back();
    } 
};
