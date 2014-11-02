class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.empty()) return 0;
        queue<string> cur, next;
        unordered_set<string> visited;
        string word;
        int step(1);
        if(start == end) return step;
        cur.push(start);
        visited.insert(start);
        
        ++step;
        while(!cur.empty()) {
            word = cur.front(); cur.pop();
            for(int i=0; i<word.size(); ++i) {
                for(char c='a'; c<='z'; ++c) {
                    if(c == word[i]) continue;
                    swap(word[i], c);
                    if(word == end) return step;
                    if(visited.find(word) == visited.end() && dict.find(word) != dict.end()) {
                        visited.insert(word);
                        next.push(word);
                    }
                    swap(word[i], c);
                }
            }
            if(cur.empty()) {
                ++step;
                cur.swap(next);
            }
        }
        return 0;
    }
};
