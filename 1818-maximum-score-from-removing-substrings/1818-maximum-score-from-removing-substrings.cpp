class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;
        stack<char> st;
        string temp = "";

        if (x >= y) {
            // First remove all "ab"
            for (char ch : s) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    result += x;
                } else {
                    st.push(ch);
                }
            }

            // Build remaining string
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            // Now remove "ba"
            for (char ch : temp) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    result += y;
                } else {
                    st.push(ch);
                }
            }
        } else {
            // First remove all "ba"
            for (char ch : s) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    result += y;
                } else {
                    st.push(ch);
                }
            }

            // Build remaining string
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            // Now remove "ab"
            for (char ch : temp) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    result += x;
                } else {
                    st.push(ch);
                }
            }
        }

        return result;
    }
};
