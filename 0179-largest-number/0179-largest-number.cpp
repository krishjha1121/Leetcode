class Solution {
public:
    static bool comp(int &x , int &y){
        string a = to_string(x);
        string b = to_string(y);

        return (a + b > b + a);
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end() , comp);

        string res ="";
        for(int i = 0 ; i < n ; i++){
            res += to_string(nums[i]);
        }
        if(res[0] == '0'){
            return "0";
        }
        return res;
    }
};