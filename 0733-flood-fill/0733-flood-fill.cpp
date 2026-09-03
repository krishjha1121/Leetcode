class Solution {
private:
    void dfs(int sr , int sc , vector<vector<int>>& image , vector<vector<int>>& ans , int initial ,
    int delRow[] , int delCol[] , int newColor){
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0 ; i < 4 ; i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != newColor && 
            image[nrow][ncol] == initial){
                dfs(nrow , ncol , image , ans , initial , delRow , delCol , newColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initial = image[sr][sc];

        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};
        dfs(sr , sc , image , ans , initial , delRow , delCol , color);
        return ans;
    }
};