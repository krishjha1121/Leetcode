class Solution {
private:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[i][j] = 1;
        int res = 1; 

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
            !vis[ni][nj] && grid[ni][nj] == 1) {
                res += dfs(ni, nj, vis, grid);
            }
        }
        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    maxi = max(maxi, dfs(i, j, vis, grid));
                }
            }
        }

        return maxi;
    }
};