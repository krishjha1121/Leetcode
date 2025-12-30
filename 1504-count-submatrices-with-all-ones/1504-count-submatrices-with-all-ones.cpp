class Solution {
private:
    int findRes(vector<int>& temp){
        int res = 0;
        int consec = 0;
        for(auto it : temp){
            if(it == 0){
                consec = 0;
            } else {
                consec++;
            }
            res += consec;
        }
        return res;
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        for(int srow = 0; srow < n; srow++){
            vector<int> v(m, 1);  
            for(int erow = srow; erow < n; erow++){
                for(int col = 0; col < m; col++){
                    v[col] = v[col] & mat[erow][col];
                }
                res += findRes(v);
            }
        }
        return res;
    }
};
