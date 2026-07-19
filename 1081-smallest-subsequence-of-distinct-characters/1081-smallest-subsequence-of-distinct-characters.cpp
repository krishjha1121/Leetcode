class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";

        vector<int> last(26 , -1);
        vector<bool> visited(26, false);
        stack<char> st;

        for(int i = n - 1; i >= 0 ; i--){
            if(last[s[i] - 'a'] == -1){
                last[s[i] - 'a'] = i;
            }
        }

        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(st.empty()){
                st.push(c);
                visited[c - 'a'] = true;
                continue;
            }

            while(!st.empty() && s[i] < st.top() && last[st.top() - 'a'] > i && !visited[s[i] - 'a']){
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            if(visited[s[i] - 'a'] == false){
                visited[s[i] - 'a'] = true;
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin() , res.end());
        return res;
    }
};