class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
    vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

        vector<int> ans(queries.size(), -1);
        int i = 0;
        int n = intervals.size();
        for (auto &[x, idx] : q) {
            while (i < n && intervals[i][0] <= x) {
                int l = intervals[i][0];
                int r = intervals[i][1];

                int len = r - l + 1;

                pq.push({len, r});
                i++;
            }
            while (!pq.empty() && pq.top().second < x) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};