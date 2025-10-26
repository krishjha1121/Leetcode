class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), x = nums2[n];
        int mini = INT_MAX;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(nums1[i] - nums2[i]);
            int dist = min((abs(nums1[i] - x) + 1), (abs(nums2[i] - x) + 1));
            if(min(nums1[i] , nums2[i]) <= x && x <= max(nums1[i], nums2[i])) dist = 1;
            mini = min(mini, dist);
        }
        ans += mini;
        return ans;
    }
};