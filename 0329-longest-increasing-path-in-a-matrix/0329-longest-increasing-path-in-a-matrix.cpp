class Solution {
private:
    int n, m;
    vector<vector<int>> matrix;
    vector<vector<int>> dp;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int dfs(int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        int ans = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(ni, nj));
            }
        }
        return dp[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        this->matrix = matrix;
        dp.assign(n, vector<int>(m, 0));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, dfs(i, j));
            }
        }

        return maxi;
    }
};