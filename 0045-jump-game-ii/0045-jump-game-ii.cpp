class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j < n - 1){
            int maxi = 0;
            for(int idx = i; idx <= j; idx++){
                maxi = max(maxi, idx + nums[idx]);
            }
            ans++;
            i = j + 1;
            j = maxi;
        }
        return ans;
    }
};