class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> res = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;
            
            vis[row][col] = 1;
            res[row][col] = color;
            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == image[sr][sc] && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                }
            }
        }
        return res;
    }
};