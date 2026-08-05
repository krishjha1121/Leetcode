class Solution {
private:
    int n;
    void solve(int i, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums, set<vector<int>>& st){
        if (i == n) {
            vector<int> cur = temp;
            ranges::sort(cur);
            if (st.insert(cur).second) res.push_back(cur);
            return;
        }
        temp.push_back(nums[i]);
        solve(i + 1, temp, res, nums, st);
        temp.pop_back();
        solve(i + 1, temp, res, nums, st);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> st;
        solve(0, temp, res, nums, st);
        return res;
    }
};