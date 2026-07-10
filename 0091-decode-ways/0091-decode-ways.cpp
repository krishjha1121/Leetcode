class Solution {
private:
    int n;
    int solve(int i, string& s, vector<int> &dp){
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ways = solve(i + 1, s, dp);
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) ways += solve(i + 2, s, dp);
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};