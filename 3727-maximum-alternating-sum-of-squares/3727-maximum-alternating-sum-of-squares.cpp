class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) nums[i] *= -1;
        }
        ranges::sort(nums);
        int i = 0;
        int j = n - 1;

        long long res = 0;
        while(i <= j){
            res += (nums[j] * nums[j] * 1LL);
            if(i < j) res -= (nums[i] * nums[i] * 1LL);
            i++;
            j--;
        }
        return res;
    }
};