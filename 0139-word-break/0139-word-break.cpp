class Solution {
private:
    unordered_set<string> dict;
    vector<int> dp;
    string s;
    int n;

    bool solve(int i) {
        if (i == n) return true;
        if (dp[i] != -1) return dp[i];

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (dict.count(word) && solve(j + 1)) return dp[i] = true;
        }
        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        n = s.size();
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.assign(n, -1);
        return solve(0);
    }
};