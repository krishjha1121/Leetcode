class Solution {
private:
    int n, m;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    bool isValid(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    long long dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
    long long currSum){
        vis[i][j] = 1;
        currSum = grid[i][j];

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(isValid(ni, nj) && !vis[ni][nj] && grid[ni][nj] > 0){
                currSum += dfs(ni, nj, grid, vis, currSum);
            }
        }

        return currSum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    long long res = dfs(i, j, grid, vis, 0);
                    if(res % k == 0) cnt++;
                }
            }
        }

        return cnt;
    }
};