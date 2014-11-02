class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board.front().empty()) return;
        const int m = board.size(), n = board.front().size();
        for(int j=0; j<n; ++j) {
            dfs(0, j, board);
            dfs(m-1, j, board);
        }
        for(int i=1; i<m-1; ++i) {
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }
private:
    //一般的变量别取 i, j， 容易和循环体的下标混。。
    void dfs(int index_i, int index_j, vector<vector<char> >&board) {
        if(index_i < 0 || index_i >= board.size() || index_j < 0 || index_j >= board[0].size()) 
            return;
        if(board[index_i][index_j] != 'O') return;
        board[index_i][index_j] = 'V';
        int direct[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        for(int k=0; k<4; ++k) {
            dfs(index_i+direct[k][0], index_j+direct[k][1], board);
        }
    }
};
