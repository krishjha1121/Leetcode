class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diag = i - j;

                mpp[diag].push_back(grid[i][j]);
            }
        }

        for (auto &it : mpp) {  
            if (it.first >= 0) {
                sort(it.second.begin(), it.second.end()); 
            } else {
                sort(it.second.rbegin(), it.second.rend()); 
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diag = i - j;

                grid[i][j] = mpp[diag].back();
                mpp[diag].pop_back();
            }
        }

        return grid;
    }
};