class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for(auto &i : nums){
            pq.push(i);
        }
        int i = 1;
        while(i < n && !pq.empty()){
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }
        int j = 0;
        while(j < n && !pq.empty()){
            nums[j] = pq.top();
            pq.pop();
            j += 2;
        }
    }
};