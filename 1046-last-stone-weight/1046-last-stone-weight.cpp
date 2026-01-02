class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            auto y = pq.top();
            pq.pop();
            auto x = pq.top();
            pq.pop();
            if(x == y){
                continue;
            }else{
                y = y - x;
                pq.push(y);
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};