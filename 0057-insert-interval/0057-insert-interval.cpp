class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        int n = intervals.size();
        bool inserted = false;
        for(int i = 0; i < n; i++){
            if(newInterval[0] <= intervals[i][1]){
                temp.push_back(newInterval);
                inserted = true;
            }
            temp.push_back(intervals[i]);
        }
        if(!inserted) temp.push_back(newInterval);
        vector<vector<int>> res = merge(temp);
        return res;
    }
};