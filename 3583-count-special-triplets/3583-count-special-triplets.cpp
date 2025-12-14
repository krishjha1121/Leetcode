class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(vector<int> &nums) {
        int n = nums.size();
        map<int, int> mpp1, mpp2;
        for (int i = 0; i < n; i++) {
            mpp2[nums[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            mpp2[curr]--;
            int req = curr * 2;
            ans = (ans + 1LL * mpp1[req] * mpp2[req]) % MOD;
            mpp1[curr]++;
        }
        return ans;
    }
    int specialTriplets(vector<int>& nums) {
        return solve(nums);
    }
};
