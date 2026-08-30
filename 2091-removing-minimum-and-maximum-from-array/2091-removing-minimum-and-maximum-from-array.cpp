class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini_idx, maxi_idx);
        int right = max(mini_idx, maxi_idx);

        int removeLeft = right + 1;
        int removeRight = n - left;
        int removeBoth = (left + 1) + (n - right);

        return min({removeLeft, removeRight, removeBoth});
    }
};