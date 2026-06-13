class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int> totalSum;

        for (int i = 0; i < n; i++) {
            int currSum = 0;

            for (int j = 0; j < words[i].size(); j++) {
                int idx = words[i][j] - 'a';
                currSum = (currSum + weights[idx]) % 26;
            }

            totalSum.push_back(currSum);
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            char currChar = 'z' - totalSum[i];
            res.push_back(currChar);
        }

        return res;
    }
};