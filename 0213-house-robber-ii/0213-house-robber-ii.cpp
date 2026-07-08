class Solution {
    int f(int idx , vector<int>& arr , vector<int> &dp){
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = arr[idx] + f(idx - 2 , arr, dp);
        int notPick = 0 + f(idx - 1 , arr, dp);

        return dp[idx] = max(pick , notPick);
    }
    int robHelper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1 , nums , dp);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        int ans1 = robHelper(temp1);
        int ans2 = robHelper(temp2);
        return max(ans1, ans2);
    }
};