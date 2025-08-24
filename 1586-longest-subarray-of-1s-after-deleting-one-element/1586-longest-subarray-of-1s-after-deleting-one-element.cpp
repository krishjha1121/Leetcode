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

        for(int left = 0; left < n; left++){
            int cnt = 0;

            for(int right = left; right < n; right++){
                if(nums[right] == 0) cnt++;
                if(cnt == 2) break;
                maxi = max(maxi, right - left + 1);
            }
        }

        return maxi - 1;
    }
};