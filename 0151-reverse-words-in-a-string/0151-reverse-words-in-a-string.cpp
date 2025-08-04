class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0, n = s.size();

        while (i < n) {
            while (i < n && s[i] == ' ') i++; // Skip leading spaces

            if (i >= n) break; // If we reach the end, break

            string temp = "";
            while (i < n && s[i] != ' ') { // Collect a word
                temp += s[i];
                i++;
            }

            st.push(temp); // Push the word into the stack
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += " "; // Avoid trailing space
        }

        return res;
    }
};