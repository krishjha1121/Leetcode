class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(auto it : nums) mpp[it]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }

        vector<int> res;
        while(!pq.empty() && k--){
            auto it = pq.top();
            pq.pop();
            res.push_back(it.second);
        }
        return res;
    }
};