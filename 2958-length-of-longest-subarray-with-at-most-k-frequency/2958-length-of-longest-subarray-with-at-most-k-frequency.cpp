class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        int i = 0;
        int j = 0;
        int maxi = 1;
        while(j < n){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(mpp[nums[i]]);
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};