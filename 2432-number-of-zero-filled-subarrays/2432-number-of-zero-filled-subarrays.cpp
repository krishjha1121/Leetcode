class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long res = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int j = i;

                while(j < n && nums[j] == 0){
                    res += (j - i + 1);
                    j++;
                }
                i = j;
            }
        }

        return res;
    }
};