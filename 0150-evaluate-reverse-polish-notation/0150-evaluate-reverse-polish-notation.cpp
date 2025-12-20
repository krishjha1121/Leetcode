class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        set<string> stt;
        stt.insert("+");
        stt.insert("*");
        stt.insert("-");
        stt.insert("/");
        for(int i = 0 ; i < n ; i++){
            if(stt.find(tokens[i]) == stt.end()){
                st.push(stoi(tokens[i]));
            }
            else if(tokens[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if(tokens[i] == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(tokens[i] == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if(tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
        }
        return st.top();
    }
};