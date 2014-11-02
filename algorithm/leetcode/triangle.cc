class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty() || triangle.front().empty()) return 0;
        const int n = triangle.size();
        vector<int> f(triangle[n-1].begin(), triangle[n-1].end());
        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
