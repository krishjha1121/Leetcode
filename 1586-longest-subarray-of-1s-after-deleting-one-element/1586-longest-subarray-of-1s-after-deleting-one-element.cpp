class Solution {
private:
    bool allOnes(vector<int>& nums){
        for(auto it : nums){
            if(it == 0) return false;
        }
        return true;
    }

public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(allOnes(nums)) return n - 1;

        int maxi = 0;

        int left = 0;
        int right = 0;
        int cnt = 0;

        while(right < n){
            if(nums[right] == 0){
                cnt++;
            }

            while(cnt > 1 && left < n){
                if(nums[left] == 0) cnt--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi - 1;
    }
};