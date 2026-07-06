class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int res = n;
        vector<int> alreadyConsumed(n, 0);
        for(int i = 0; i < n; i++){
            auto currInt = intervals[i];
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                auto nextInt = intervals[j];
                if(currInt[0] <= nextInt[0] && currInt[1] >= nextInt[1] && alreadyConsumed[j] == 0){
                    res--;
                    alreadyConsumed[j] = 1;
                }
            }
        }
        return res;
    }
};