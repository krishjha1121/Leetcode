class Solution {
private:
    int n, m;
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(i + 1, j + 1, s, t) + solve(i + 1, j, s, t);
        }else{
            return dp[i][j] = solve(i + 1, j, s, t);
        }
    }
public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, s, t);
    }
};