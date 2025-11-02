class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (const auto& guard : guards) {
            vis[guard[0]][guard[1]] = -1;  
        }
        for (const auto& wall : walls) {
            vis[wall[0]][wall[1]] = 1; 
        }
        int delrow[] = {-1, 0, 1, 0};  
        int delcol[] = {0, 1, 0, -1};  
        for (const auto& guard : guards) {
            int i = guard[0], j = guard[1];
            for (int k = 0; k < 4; ++k) {
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                while(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol]!= 1 && vis[nrow][ncol] != -1) {
                    vis[nrow][ncol] = 2;  
                    nrow += delrow[k];
                    ncol += delcol[k];
                }
            }
        }
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(vis[i][j] == 0) {
                    ++unguardedCount;
                }
            }
        }
        return unguardedCount;
    }
};
