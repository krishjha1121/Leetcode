class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int hillvalleyCount = 0;

        for(int i = 1; i < n; i++){
            int last = -1;
            int ahead = -1;

            for(int j = i - 1; j >= 0; j--){
                if(nums[j] != nums[i]){
                    last = j;
                    break;
                }
            }

            for(int j = i + 1; j < n ; j++){
                if(nums[j] != nums[i]){
                    ahead = j;
                    break;
                }
            }

            if(last != -1 && ahead != -1 && nums[i] > nums[last] && nums[i] > nums[ahead] && nums[i] != nums[i - 1]){
                hillvalleyCount++;
            }else if(last != -1 && ahead != -1  && nums[i] < nums[last] && nums[i] < nums[ahead] && nums[i] != nums[i - 1]){
                hillvalleyCount++;
            }
        }

        return hillvalleyCount;
    }
};