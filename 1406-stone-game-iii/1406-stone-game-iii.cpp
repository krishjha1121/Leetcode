class Solution {
private:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& stones){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int result = stones[i] - solve(i + 1, stones);
        if(i + 1 < n) result = max(result, stones[i] + stones[i + 1] - solve(i + 2, stones));
        if(i + 2 < n) result = max(result, stones[i] + stones[i + 1] + stones[i + 2] - solve(i + 3, stones));
        
        return dp[i] = result;
    }
public:
    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        dp.assign(n, -1);
        int diff = solve(0, stones);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        return "Tie";
    }
};