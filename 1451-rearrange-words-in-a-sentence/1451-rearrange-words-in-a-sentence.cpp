class Solution {
public:
    string arrangeWords(string text) {
        text[0] = text[0] - 'A' + 'a';
        map<int, vector<string>> mp;
        stringstream ss(text);
        string word;
        while (ss >> word) mp[word.size()].push_back(word);
        string ans;
        for (auto &x : mp) {
            for (string &v : x.second)
                ans += v + " ";
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};
