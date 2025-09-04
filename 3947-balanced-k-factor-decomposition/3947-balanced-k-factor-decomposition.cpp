class Solution {
private:
    void dfs(int remaining, int partsLeft, vector<int>& currentPartition) {
        if (partsLeft == 1) {
            currentPartition.push_back(remaining);
            evaluatePartition(currentPartition);
            currentPartition.pop_back();
            return;
        }

        for (int i = 1; i <= sqrt(remaining); i++) {
            if (remaining % i == 0) {
                currentPartition.push_back(i);
                dfs(remaining / i, partsLeft - 1, currentPartition);
                currentPartition.pop_back();

                if (i != remaining / i) {
                    currentPartition.push_back(remaining / i);
                    dfs(i, partsLeft - 1, currentPartition);
                    currentPartition.pop_back();
                }
            }
        }
    }

    void evaluatePartition(const vector<int>& partition) {
        int mx = *max_element(partition.begin(), partition.end());
        int mn = *min_element(partition.begin(), partition.end());
        int diff = mx - mn;

        if (diff < bestDiff) {
            bestDiff = diff;
            bestPartition = partition;
        }
    }

    
public:
    int bestDiff = INT_MAX;              
    vector<int> bestPartition;           

    vector<int> minDifference(int n, int k) {
        vector<int> currentPartition;
        dfs(n, k, currentPartition);
        return bestPartition;
    }
};
