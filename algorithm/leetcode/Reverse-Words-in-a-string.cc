class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string res, word;
        for(auto x : s) {
            if(x == ' ') {
                if(!word.empty()) {
                    reverse(word.begin(), word.end());
                    res += word + ' ';
                    word.clear();
                }
                continue;
            }
            word.push_back(x);
        }
        if(!word.empty()) { //do not forget
          reverse(word.begin(), word.end());
          res += word + ' ';
        }
        if(!res.empty()) res.pop_back();
        reverse(res.begin(), res.end());
        res.swap(s);
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        //reverse the whose string first
        reverse(s.begin(), s.end());
        
        //reverse each words separately
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == ' ') continue;
            assert(s[i] != ' ');
            int j=i;
            while(j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
            i = j;
        }
        
        //remove extra spaces
        int trail = s.size()-1;
        while(trail >=0 && s[trail] == ' ') --trail;
        int i(0), p(0);
        for(; i<=trail; ++i) {
            if(s[i] != ' ' || (p > 0 && s[p-1] != ' '))
                s[p++] = s[i];
        }
        s = s.substr(0, p);
    }
};
