class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int currMinSum = 0;
        int maxiSum = INT_MIN;
        int miniSum = INT_MAX;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0; i < n; i++){
            //Normal Kadane's
            currSum += nums[i];
            maxiSum = max(maxiSum, currSum);
            if(currSum < 0) currSum = 0;

            //Kadane's with min to find miniSubarray
            currMinSum += nums[i];
            miniSum = min(miniSum, currMinSum);
            if(currMinSum > 0) currMinSum = 0;
        }

        if(totalSum == miniSum) return maxiSum;
        return max(maxiSum, totalSum - miniSum);
    }
};