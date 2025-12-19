class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        for(auto it : nums){
            mpp[it]++;
        }
        int repeated = 0;
        for(auto it : mpp){
            if(it.second == 2) {
                repeated = it.first;
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(mpp.find(i) == mpp.end()){
                return {repeated, i};
            }
        }
        return {0, 0};
    }
};