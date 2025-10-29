class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(abs(nums[i]));
        }
        int cnt = (nums.size() & 1) ? (nums.size() / 2) + 1 : (nums.size() / 2);
        // while(!pq.empty()){
        //     cout << pq.top() << ' ';
        //     pq.pop();
        // }
        // cout << cnt << endl;
        while(cnt > 0){
            res += (pq.top() * pq.top() * 1LL);
            cout << res << endl;
            pq.pop();
            cnt--;
        }
        while(!pq.empty()){
            res -= (pq.top() * pq.top() * 1LL);
            cout << res << endl;
            pq.pop();
        }
        return res;
    }
};