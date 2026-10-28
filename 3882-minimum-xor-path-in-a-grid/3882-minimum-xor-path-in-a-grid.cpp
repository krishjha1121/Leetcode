class Solution {
private:
    int n, m, K;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int currxor, vector<vector<int>>& grid) {
        currxor ^= grid[i][j];

        if (i == n - 1 && j == m - 1) return currxor;
        if (dp[i][j][currxor] != -1) return dp[i][j][currxor];

        int right = INT_MAX;
        int down = INT_MAX;

        if (j + 1 < m) right = solve(i, j + 1, currxor, grid);
        if (i + 1 < n) down = solve(i + 1, j, currxor, grid);

        return dp[i][j][currxor] = min(right, down);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxVal = 0;
        for (auto& row : grid){
            for (int x : row){
                maxVal = max(maxVal, x);
            }
        }
        K = 1;
        while (K <= maxVal) K *= 2;

        dp.assign(n, vector<vector<int>>(m, vector<int>(K, -1)));
        return solve(0, 0, 0, grid);
    }
};