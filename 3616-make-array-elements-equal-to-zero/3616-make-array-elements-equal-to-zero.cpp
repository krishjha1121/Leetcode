class Solution {
private:
    bool check(vector<int> v , int start , int dir){
        int n = v.size();
        while(start >= 0 and start < n){
            if(v[start] == 0){
                start += dir;
            }
            else if(v[start] > 0){
                v[start]--;
                dir = -dir;
                start += dir;
            }
        }

        for(int &i : v){
            if(i != 0) return false;
        }
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                if(check(nums, i , 1)) res++;
                if(check(nums, i , -1)) res++;
            }
        }

        return res;
    }
};