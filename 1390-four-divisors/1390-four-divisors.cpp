class Solution {
private:
    pair<bool, int> onlyFour(int n){
        int sum = 0;
        bool flag = true;
        int cnt = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                sum += i;
                cnt++;
                if(n / i != i){
                    sum += (n / i);
                    cnt++;
                }
                if(cnt > 4) return {false, 0};
            }
        }
        if(cnt == 4) return {true, sum};
        return {false, 0};
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pair<bool, int> temp = onlyFour(nums[i]);
            if(temp.first) {
                res += temp.second;
            }
        }
        return res;
    }
};