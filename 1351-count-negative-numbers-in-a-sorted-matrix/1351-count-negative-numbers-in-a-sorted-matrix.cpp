class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            int firstNeg = m; 
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (grid[i][mid] < 0) {
                    firstNeg = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cnt += (m - firstNeg);
        }
        return cnt;
    }
};
