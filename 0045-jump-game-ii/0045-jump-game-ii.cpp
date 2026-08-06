class Solution {
private:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& nums) {
        if (i >= n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for (int jump = 1; jump <= nums[i]; jump++) {
            int temp = solve(i + jump, nums);
            if (temp != INT_MAX) ans = min(ans, 1 + temp);
        }
        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
};