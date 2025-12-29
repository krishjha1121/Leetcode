class Solution {
public:
    int dfs(int row , int col , vector<vector<int>>& grid , int id){
        int n = grid.size();
        if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != 1){
            return 0;
        }
        grid[row][col] = id;
        int delrow[] = {0 , 1 , 0 , -1};
        int delcol[] = {1 , 0 , -1 , 0};
        int size = 1;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            size += dfs(nrow , ncol , grid , id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mpp; // id no of island -> size of island
        int id = 2;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int size = dfs(i , j , grid , id);
                    maxi = max(maxi , size);
                    mpp[id] = size;
                    id++;
                }
            }
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){ // ask the ngbrs about their max size and add 1 to it
                    set<int> st;
                    int delrow[] = {0 , 1 , 0 , -1};
                    int delcol[] = {1 , 0 , -1 , 0};
                    for(int x = 0 ; x < 4 ; x++){
                        int i_ = i + delrow[x];
                        int j_ = j + delcol[x];
                        if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n &&
                        grid[i_][j_] != 0) st.insert(grid[i_][j_]);
                    }
                    int currSize = 1;
                    for(auto id : st){
                        currSize += mpp[id];
                    }
                    maxi = max(maxi , currSize);
                }
            }
        }
        return maxi;
    }
};