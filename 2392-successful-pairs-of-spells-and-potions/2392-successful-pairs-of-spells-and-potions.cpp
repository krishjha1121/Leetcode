class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> res(n);
        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++){
            long long x = ceil((double)success / spells[i]);

            auto it = lower_bound(potions.begin(), potions.end(), x);
            
            if(it == potions.end()) {
                res[i] = 0;
                continue;
            }

            int numberOfCandidates = potions.size() - (it - potions.begin());
            res[i] = numberOfCandidates; 
        }
        
        return res;
    }
};