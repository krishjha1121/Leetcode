class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> result;

        for(int i = 0; i < n + m - 1; i++){
            vector<int> temp;

            int row = i < m ? 0 : i - m + 1;
            int col = i < m ? i : m - 1;

            while(row < n && col > -1){
                temp.push_back(mat[row][col]);
                row++;
                col--;
            }

            if(i % 2 == 0){
                for(int idx = temp.size() - 1; idx >= 0; idx--){
                    result.push_back(temp[idx]);
                }
            }else{
                for(int idx = 0; idx < temp.size(); idx++){
                    result.push_back(temp[idx]);
                }
            }
        }

        return result;
    }
};