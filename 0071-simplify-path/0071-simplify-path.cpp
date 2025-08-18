class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;

        for (int i = 0; i < n; ) {
            if (path[i] == '/') {
                i++;
                continue;
            }

            string temp;
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if (temp == ".") {
                continue;
            } 
            else if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } 
            else {
                st.push(temp);
            }
        }

        // Build result
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res.empty()) return "/";
        return res;
    }
};
