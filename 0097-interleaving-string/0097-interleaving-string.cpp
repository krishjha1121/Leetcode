class Solution {
private:
    int n, m;
    vector<vector<int>> memo;

    bool solve(int i, int j, string &s1, string &s2, string &s3) {
        if (i == n && j == m) return true;
        if (memo[i][j] != -1) return memo[i][j];

        int k = i + j;
        if (i < n && s1[i] == s3[k]) {
            if (solve(i + 1, j, s1, s2, s3))
                return memo[i][j] = true;
        }
        if (j < m && s2[j] == s3[k]) {
            if (solve(i, j + 1, s1, s2, s3))
                return memo[i][j] = true;
        }
        return memo[i][j] = false;
}

public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();

        if (n + m != s3.size()) return false;

        memo.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s1, s2, s3);
    }
};