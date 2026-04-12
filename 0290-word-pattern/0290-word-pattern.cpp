class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp;
        stringstream ss(s);
        while (ss >> temp) {
            words.push_back(temp);
        }
        if (words.size() != pattern.size()) return false;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2; 
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];
            if (mp1.count(ch)) {
                if (mp1[ch] != word) return false;
            } else {
                mp1[ch] = word;
            }
            
            if (mp2.count(word)) {
                if (mp2[word] != ch) return false;
            } else {
                mp2[word] = ch;
            }
        }
        
        return true;
    }
};