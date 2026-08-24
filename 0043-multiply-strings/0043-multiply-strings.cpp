class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> result(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            int carry = 0;

            for (int j = len2 - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int pos = i + j + 1;
                int sum = n1 * n2 + result[pos] + carry;

                result[pos] = sum % 10;
                carry = sum / 10;
            }

            result[i] += carry;
        }
        string ans;
        int i = 0;
        while (i < result.size() && result[i] == 0) {
            ++i;
        }

        while (i < result.size()) {
            ans += char(result[i] + '0');
            ++i;
        }

        return ans.empty() ? "0" : ans;
    }
};