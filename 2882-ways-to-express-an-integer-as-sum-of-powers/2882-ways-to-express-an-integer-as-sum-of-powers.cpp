class Solution {
private:
    int mod = 1e9 + 7;
    int solve(int n, int num, int x, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;

        int currVal = pow(num, x);
        if(currVal > n) return 0;

        if(dp[n][num] != -1) return dp[n][num];

        int take = solve(n - currVal, num + 1, x, dp);
        int notTake = solve(n, num + 1, x, dp);

        return dp[n][num] = (take + notTake) % mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int>(301, -1));
        return solve(n, 1, x, dp);
    }
};