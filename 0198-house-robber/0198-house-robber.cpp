class Solution {
private:
    int f(int idx , vector<int>& arr , vector<int> &dp){
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = arr[idx] + f(idx - 2 , arr, dp);
        int notPick = 0 + f(idx - 1 , arr, dp);

        return dp[idx] = max(pick , notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1 , nums , dp);
    }
};