class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;                
        int lastTimestamp = 0;
        vector<int> ans(n, 0);
        for (auto it : logs) {
            int i = 0;
            string a = "";
            while (it[i] != ':') {
                a += it[i];
                i++;
            }
            int id = stoi(a);
            i++; 
            string action = "";
            while (it[i] != ':') {
                action += it[i];
                i++;
            }
            i++; 
            string b = "";
            while (i < it.size()) {
                b += it[i];
                i++;
            }
            int time = stoi(b);
            if (action == "start") {
                if (!st.empty()) {
                    ans[st.top()] += (time - lastTimestamp);
                }
                st.push(id);
                lastTimestamp = time;
            } 
            else {
                ans[st.top()] += (time + 1 - lastTimestamp);
                st.pop();
                lastTimestamp = time + 1;
            }
        }
        return ans;
    }
};
