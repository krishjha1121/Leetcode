class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int result = 0;
        for(int i = 0; i < n;){
            int j = i;
            int maxi = 0;
            int sum = 0;
            while(colors[j] == colors[i] && j < n){
                maxi = max(maxi, neededTime[j]);
                sum += neededTime[j];
                j++;
            }
            result += sum - maxi;
            i = j;
        }
        return result;
    }
};