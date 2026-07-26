class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        int prod = 1;
        for(int i = n - 1; i >= n - 3; i--) prod *= nums[i];
        return max(nums[0] * nums[1] * nums[n - 1], prod);
    }
};