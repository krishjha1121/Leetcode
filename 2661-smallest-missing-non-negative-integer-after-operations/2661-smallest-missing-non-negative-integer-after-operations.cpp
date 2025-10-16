class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

        // Step 1: Normalize numbers & count frequencies of x % value
        for(int &x : nums) {
            int r = ((x % value) + value) % value;  // ensures positive modulo
            freq[r]++;
        }

        // Step 2: Find the smallest valid mex
        int mex = 0;
        while(true) {
            int r = mex % value;
            if(freq[r] > 0) {
                freq[r]--;  // use one occurrence
                mex++;
            } else {
                break;
            }
        }
        return mex;
    }
};
