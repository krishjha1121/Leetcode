class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxiVal = *max_element(nums.begin(), nums.end());
        int maxiLen = 0;
        int currLen = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == maxiVal){
                currLen++;
                maxiLen = max(maxiLen, currLen);
            }else{
                currLen = 0;
            }
        }

        return maxiLen;
    }
};