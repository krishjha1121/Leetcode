class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        for (auto &p : pos) {
            vector<int> &v = p.second;
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) {
                ans = min(ans, v[i + 2] - v[i]);
            }
        }
        return ans == n + 1 ? -1 : ans * 2;
    }
};