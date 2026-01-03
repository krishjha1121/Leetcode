class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    string states[12] = {
        "RGY", "RYG", "GRY", "GYR",
        "YRG", "YGR", "RGR", "RYR",
        "GRG", "GYG", "YRY", "YGY"
    };
    vector<vector<int>> dp;
    bool compatible(const string &a, const string &b) {
        for (int i = 0; i < 3; i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
    int solve(int row, int prev) {
        if (row == n) return 1;
        if (dp[row][prev] != -1) return dp[row][prev];
        long long ways = 0;
        for (int i = 0; i < 12; i++) {
            if (compatible(states[prev], states[i])) {
                ways = (ways + solve(row + 1, i)) % MOD;
            }
        }
        return dp[row][prev] = ways;
    }
    int numOfWays(int rows) {
        n = rows;
        dp.assign(n, vector<int>(12, -1));
        long long result = 0;
        for (int i = 0; i < 12; i++) {
            result = (result + solve(1, i)) % MOD;
        }
        return result;
    }
};
