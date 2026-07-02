class Solution {
private:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool dfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& best, 
    int health) {
        if (health < 1) return false;
        if (i == n - 1 && j == m - 1) return true;

        if (best[i][j] >= health) return false;

        best[i][j] = health;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (isValid(ni, nj)) {
                int newHealth = health - grid[ni][nj];
                if (dfs(ni, nj, grid, best, newHealth)) return true;
            }
        }
        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, -1));
        return dfs(0, 0, grid, best, health - grid[0][0]);
    }
};