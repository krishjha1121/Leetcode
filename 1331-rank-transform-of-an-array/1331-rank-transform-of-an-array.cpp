class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        map<int, int> mpp;
        int rank = 1;
        for(auto it : temp){
            if(!mpp.count(it)){
                mpp[it] = rank++;
            }
        }

        vector<int> ans;
        for(auto it : arr){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};