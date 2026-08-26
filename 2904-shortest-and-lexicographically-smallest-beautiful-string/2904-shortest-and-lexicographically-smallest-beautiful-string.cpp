class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b){
            if (a.first != b.first) return a.first > b.first;   
            return a.second > b.second;     
        }
    };

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int cnt = 0;
        priority_queue<pair<int, string>,vector<pair<int, string>>,Compare> pq;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') cnt++;
            while (cnt >= k) {
                string sub = s.substr(left, right - left + 1);
                int len = sub.length();
                pq.push({len, sub});
                if (s[left] == '1') cnt--;
                left++;
            }
        }

        return pq.empty() ? "" : pq.top().second;
    }
};