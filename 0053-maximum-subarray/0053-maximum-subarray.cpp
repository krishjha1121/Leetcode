class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int i = 0, j = 0;
        int sum = 0;
        while(j < n){
            sum += nums[j];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
                i = j;
            }
            j++;
        }
        return maxi;
    }
};