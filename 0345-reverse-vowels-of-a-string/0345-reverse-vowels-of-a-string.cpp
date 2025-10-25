class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch); 
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string reverseVowels(string s) {
        string temp;
        for (char ch : s) {
            if (isVowel(ch)) temp += ch;
        }
        reverse(temp.begin(), temp.end());
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = temp[cnt];
                cnt++;
            }
        }
        return s;
    }
};
