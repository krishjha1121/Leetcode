class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int opening = 0;
        int closing = 0;
        string res = "";
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') opening++;
            else closing++;

            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(closing == opening){
                    st.pop();
                    closing = 0;
                    opening = 0;
                    continue;
                }else{
                    while(!st.empty()){
                        res += st.top();
                        st.pop();
                    }
                    st.push(res.back());
                    res.pop_back();
                    res += s[i];
                }
            }
        }

        return res;
    }
};