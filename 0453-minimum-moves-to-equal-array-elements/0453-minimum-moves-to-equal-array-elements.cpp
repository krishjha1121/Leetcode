class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        if(mini == maxi) return 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += abs(nums[i] - mini);
        }

        return res;
    }
};