class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return n;
        if(n == 2){
            if(nums[0] != nums[1]) return n;
            else return 1;
        }
        vector<int> diff;
        for(int i = 0 ; i < n - 1 ; i++){
            int x = nums[i+1] - nums[i];
            diff.push_back(x);
        }
        int last = diff[0];
        int cnt = 0;
        for(int i = 1 ; i < diff.size() ; i++){
            if(diff[i] == 0){
                cnt++;
                // last = diff[i];
                continue;
            }
            if(last <= 0 && diff[i] < 0){
                cnt++;
            }
            else if(last >= 0 && diff[i] > 0){
                cnt++;
            }
            last = diff[i];
        }
        if((cnt + (last == 0 ? 2 : 0)) == n){
            return 1;
        } 
        return n - cnt;
    }
};