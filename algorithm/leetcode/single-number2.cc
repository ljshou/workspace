class Solution {
public:
    int singleNumber(int A[], int n) {
        assert(A && n > 0);
        int m = sizeof(int) * 8;
        int f[m];
        fill(f, f+m, 0);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(A[i] & (1 << j)) ++f[j];
            }
        }
        int res(0);
        for(int j=0; j<m; ++j) {
            if(f[j] % 3 != 0) {
                res |= (1 << j);
            }
        }
        return res;
    }
};
