class Solution {
public:
    int solve(int i, vector<int>& start,vector<int>& end, vector<int>& profit, vector<int>& dp) {

        int n = start.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int skip = solve(i + 1, start, end, profit, dp);

        int next = lower_bound(start.begin() + i + 1,start.end(),end[i]) - start.begin();
        int take = profit[i] + solve(next,start,end,profit,dp);

        return dp[i] = max(skip, take);
    }

    int jobScheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }
        sort(jobs.begin(), jobs.end());
        vector<int> start(n);
        vector<int> end(n);
        vector<int> profitNew(n);
        for (int i = 0; i < n; i++) {
            start[i] = get<0>(jobs[i]);
            end[i] = get<1>(jobs[i]);
            profitNew[i] = get<2>(jobs[i]);
        }
        vector<int> dp(n, -1);
        return solve(0, start, end, profitNew, dp);
    }
};