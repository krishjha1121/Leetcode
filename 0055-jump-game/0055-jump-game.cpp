class Solution {
private:
    int n;
    vector<int> dp;
    bool solve(int i, vector<int>& nums){
        if(i == n - 1) return true;
        if(i >= n) return false;
        if(dp[i] != -1) return dp[i];
        for(int k = 1; k <= nums[i]; k++){
            if(solve(i + k, nums)){
                return true;
            }
        }
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
};