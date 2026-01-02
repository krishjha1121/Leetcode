class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int, int> mpp;
        for(auto it : nums) mpp[it]++;
        for(auto it : mpp){
            if(it.second == n) return it.first;
        }
        return -1;
    }
};