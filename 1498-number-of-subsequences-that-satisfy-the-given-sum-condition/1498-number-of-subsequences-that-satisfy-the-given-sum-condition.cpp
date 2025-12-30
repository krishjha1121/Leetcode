class Solution {
public:
    const int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> noOfsub(n + 1 , 1);
        for(int i = 1 ; i <= n ; i++){
            noOfsub[i] = (2 * noOfsub[i - 1]) % mod;
        }
        int i = 0;
        int j = n - 1;
        int res = 0;
        while(i <= j){
            if(nums[j] + nums[i] <= target){
                res = (res + noOfsub[j - i]) % mod;
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};