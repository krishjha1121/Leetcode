class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;
    bool isValid(int i, int j){
        return i < n && i >= 0 && j < m && j >= 0;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            if(isValid(nrow, ncol) && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    res++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return res;
    }
};