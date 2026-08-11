class Solution {
private:
    int n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool dfs(int i, int j, int level, vector<vector<int>>& grid,
    vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) return true;
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < n &&
                !vis[ni][nj] &&
                grid[ni][nj] <= level) {

                if (dfs(ni, nj, level, grid, vis)) return true;
            }
        }
        return false;
    }

    bool canReach(int level, vector<vector<int>>& grid) {
        if (grid[0][0] > level) return false;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        return dfs(0, 0, level, grid, vis);
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0];
        int high = n * n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canReach(mid, grid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};