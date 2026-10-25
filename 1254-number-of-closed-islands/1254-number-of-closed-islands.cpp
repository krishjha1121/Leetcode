class Solution {
private:
    int n, m;
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};

    bool isBoundary(int i, int j){
        return (i == 0 || i == n - 1 || j == 0 || j == m - 1);
    }

    bool isValid(int i, int j){
        return (i < n && j < m && i >= 0 && j >= 0);
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(isValid(ni, nj) && grid[ni][nj] == 0) {
                dfs(ni, nj, grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isBoundary(i, j) && grid[i][j] == 0){
                    dfs(i, j, grid);
                }
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    res++;
                    dfs(i, j, grid);
                }
            }
        }

        return res;
    }
};