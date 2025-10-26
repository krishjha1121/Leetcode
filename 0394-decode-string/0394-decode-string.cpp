class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        string res = "";
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == ']'){
                string rep = "";
                while(!st.empty() && st.top() != '['){
                    rep = st.top() + rep;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                int cnt = stoi(num);
                while(cnt--){
                    for(int i = 0; i < rep.size(); i++){
                        st.push(rep[i]);
                    }
                }
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};