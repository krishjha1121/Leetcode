class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int res = 0;
        for(int i = 0; i < n; i++){
            if(citations[i] >= n - i){
                res = max(res, n - i);
            }
        }

        return res;
    }
};