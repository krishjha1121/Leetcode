class Solution {
private:
    int n;
    void solve(vector<int>& nums, vector<int>& temp,
    vector<vector<int>>& res, vector<bool>& vis) {

        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;

            temp.push_back(nums[i]);
            solve(nums, temp, res, vis);
            temp.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(n, false);
        solve(nums, temp, res, vis);
        return res;
    }
};