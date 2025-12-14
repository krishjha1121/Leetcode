class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mini = *min_element(complexity.begin(), complexity.end());
        int cnt = 0;
        for(auto it : complexity){
            if(it == mini) cnt++;
        }
        if(cnt > 1 || complexity[0] != mini) return 0;
        long long ans = 1;
        for(int i = 2; i < n; i++){
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};