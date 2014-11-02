class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int res(0);
        if(num.empty()) return 0;
        unordered_set<int> hash(num.begin(), num.end());
        
        int len(0);
        while(!hash.empty()) {
            int x = *hash.begin();
            len = 0;
            for(int i=x; hash.find(i) != hash.end(); ++i) {
                ++len;
                hash.erase(i);
            }
            for(int i=x-1; hash.find(i) != hash.end(); --i) {
                ++len; 
                hash.erase(i);
            }
            res = max(res, len);
        }
        
        return res;
    }
};
