class Solution {
public:
    //D.P.
    //compute from down to top is much easier
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty() || triangle.front().empty()) return 0;
        vector<int> f(triangle.back().begin(), triangle.back().end());
        for(int i=triangle.size()-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            } 
        }
        return f[0];
    }
};
