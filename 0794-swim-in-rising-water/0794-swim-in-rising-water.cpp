class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool canReachEnd(int t, vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] > t) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (auto &dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                    !vis[ni][nj] && grid[ni][nj] <= t) {
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = n * n - 1;
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canReachEnd(mid, grid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
