class Solution {
public:
    int T = 1e9 + 7;

    int solve(int i, int j, int prev, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        
        // Out of bounds
        if (i >= grid.size() || j >= grid[0].size()) 
            return 0;

        // Reached destination
        if (i == grid.size() - 1 && j == grid[0].size() - 1) 
            return 1;

        // Already computed
        if (dp[i][j][prev + 1] != -1) 
            return dp[i][j][prev + 1];

        // If current cell is a mirror
        if (grid[i][j] == 1) {
            if (prev == 0) { 
                // Entered from left (moving right) → reflected down
                return solve(i + 1, j, 1, grid, dp);
            }
            if (prev == 1) { 
                // Entered from above (moving down) → reflected right
                return solve(i, j + 1, 0, grid, dp);
            }
        }

        // Otherwise, move normally
        int right = solve(i, j + 1, 0, grid, dp);  // go right, prev=0
        int down  = solve(i + 1, j, 1, grid, dp);  // go down, prev=1

        return dp[i][j][prev + 1] = (right + down) % T;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));
        return solve(0, 0, -1, grid, dp);
    }
};
