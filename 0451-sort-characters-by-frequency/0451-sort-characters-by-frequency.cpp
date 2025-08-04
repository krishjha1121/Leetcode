class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, int>> pq;

        map<char , int> mpp;
        for(auto it : s){
            mpp[it]++;
        }

        for(auto it : mpp){
            pq.push({it.second , it.first});
        }

        string res = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            while(freq--)
                res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};