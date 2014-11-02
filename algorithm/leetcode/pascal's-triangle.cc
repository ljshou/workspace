class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> path;
        vector<vector<int> > res;
        if(numRows <= 0) return res;
        for(int i=0; i<numRows; ++i) {
            for(int j=(int)path.size()-1; j>=1; --j) {
                path[j] += path[j-1];
            }
            path.push_back(1);
            res.push_back(path);
        }
        return res;
    }
};
