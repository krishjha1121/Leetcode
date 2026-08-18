class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        int currEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < currEnd) {
                res++;
            } else {
                currEnd = intervals[i][1];
            }
        }
        return res;
    }
};