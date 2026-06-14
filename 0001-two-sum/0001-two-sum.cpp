class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numToIndex;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int req = target - nums[i];
            if(numToIndex.count(req)){
                return {i, numToIndex[req]};
            }
            numToIndex[nums[i]] = i;
        }
        return {-1, -1};
    }
};