class Solution {
private:
    int n;

    void solve(int idx, int currSum, vector<int>& candidates, int target,
    vector<vector<int>>& res, vector<int>& temp) {
        if (currSum == target) {
            res.push_back(temp);
            return;
        }

        if (currSum > target || idx == n)
            return;

        temp.push_back(candidates[idx]);
        solve(idx, currSum + candidates[idx], candidates, target, res, temp);
        temp.pop_back();

        solve(idx + 1, currSum, candidates, target, res, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, 0, candidates, target, res, temp);
        return res;
    }
};