class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        int maxi = 0;
        int res = 0;
        for(auto it : mpp){
            if(it.second > maxi){
                res = it.second;
                maxi = it.second;
            }else if(it.second == maxi){
                res += it.second;
            }
        }

        return res;
    }
};