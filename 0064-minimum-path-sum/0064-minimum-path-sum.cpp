class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m){
        if(i >= n || j >= m) return INT_MAX;
        if(i == n - 1 && j == m - 1) return grid[i][j]; 
        if(dp[i][j] != -1) return dp[i][j];

        int currSum = grid[i][j];
        int right = solve(i + 1, j, grid, dp, n, m);
        int down = solve(i, j + 1, grid, dp, n, m);

        if (right != INT_MAX) right += currSum;
        if (down != INT_MAX)  down += currSum;

        return dp[i][j] = min(right, down);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, dp, n, m);
    }
};