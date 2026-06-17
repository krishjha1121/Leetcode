class Solution {
private:
    bool dfs(int row, int col, int idx, vector<vector<char>>& board, 
    vector<vector<int>>& vis, string& word) {
        if (idx == word.size()) return true;
        int n = board.size();
        int m = board[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col] || board[row][col] != word[idx]) {
            return false;
        }

        vis[row][col] = true;

        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (dfs(nrow, ncol, idx + 1, board, vis, word)) {
                return true;
            }
        }

        vis[row][col] = false; 
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) { // Start DFS only if the first character matches
                    if (dfs(i, j, 0, board, vis, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
