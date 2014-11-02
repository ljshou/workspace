class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> path;

        for(int i=0; i<=rowIndex; ++i) {
            for(int j=(int)path.size()-1; j>=1; --j) {
                path[j] += path[j-1];
            }
            path.push_back(1);
        }
        return path;
    }
};
