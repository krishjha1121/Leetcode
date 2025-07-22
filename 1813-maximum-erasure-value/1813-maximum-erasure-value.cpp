class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, maxi = 0;
        map<int, int> mpp;

        while (j < n) {
            int currEle = nums[j];
            sum += currEle;
            mpp[currEle]++;

            while (mpp[currEle] > 1) {
                mpp[nums[i]]--;
                sum -= nums[i];
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            maxi = max(maxi, sum);
            j++;
        }

        return maxi;
    }
};
