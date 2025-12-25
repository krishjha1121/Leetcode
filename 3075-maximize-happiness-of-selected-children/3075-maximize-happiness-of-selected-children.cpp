class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long result = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int currCnt = 0;
        int idx = 0;
        while(k--){
            happiness[idx] = max(happiness[idx] - currCnt, 0);
            result += happiness[idx];
            currCnt++, idx++;
        }
        return result;
    }
};