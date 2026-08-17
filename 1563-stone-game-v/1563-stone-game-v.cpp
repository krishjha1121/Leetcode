class Solution {
public:
    int solve(int l, int r, vector<int> &prefix, vector<vector<int>> &dp){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for (int k = l; k < r; k++) {
            int suml = prefix[k] - (l > 0 ? prefix[l - 1] : 0);
            int sumr = prefix[r] - prefix[k];

            if (suml < sumr) {
                ans = max(ans, suml + solve(l, k,prefix,dp));
            }
            else if (suml > sumr) {
                ans = max(ans, sumr + solve(k + 1, r,prefix,dp));
            }
            else {
                ans = max(ans, suml + max(solve(l, k,prefix,dp),solve(k + 1, r,prefix,dp)));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];
        for(int i=1;i<n;i++){
            prefix[i] = stoneValue[i] + prefix[i-1];
        }
        return solve(0,n-1,prefix,dp);
    }
};