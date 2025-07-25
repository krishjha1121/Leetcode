class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = 0;
        int maxi = INT_MIN;
        int negCount = 0;
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negCount++;
                maxi = max(maxi, nums[i]);
            }
            mpp[nums[i]]++;
        }

        if(negCount == nums.size()){
            return maxi;
        }else{
            for(auto it : mpp){
                if(it.first >= 0){
                    result += it.first;
                }
            }
            return result;
        }
    }
};