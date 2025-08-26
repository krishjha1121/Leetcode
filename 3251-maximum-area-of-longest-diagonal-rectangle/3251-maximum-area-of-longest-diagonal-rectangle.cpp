class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxiArea = INT_MIN;
        double maxDiag = -1; 

        for (auto& it : dimensions) {
            int len = it[0];
            int wid = it[1];

            int area = len * wid;
            double diag = sqrt(1.0 * len * len + 1.0 * wid * wid);

            if (diag > maxDiag || (diag == maxDiag && area > maxiArea)) {
                maxDiag = diag;
                maxiArea = area;
            }
        }

        return maxiArea;
    }
};
