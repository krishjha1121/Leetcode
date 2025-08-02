class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int minVal = INT_MAX;

        for (int fruit : basket1) {
            freq[fruit]++;
            minVal = min(minVal, fruit);
        }
        for (int fruit : basket2) {
            freq[fruit]--;
            minVal = min(minVal, fruit);
        }

        vector<int> toSwap;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;
            for (int i = 0; i < abs(count) / 2; ++i) {
                toSwap.push_back(fruit);
            }
        }

        sort(toSwap.begin(), toSwap.end());
        long long cost = 0;
        int half = toSwap.size() / 2;

        for (int i = 0; i < half; ++i) {
            cost += min(toSwap[i], 2 * minVal);
        }

        return cost;
    }
};
