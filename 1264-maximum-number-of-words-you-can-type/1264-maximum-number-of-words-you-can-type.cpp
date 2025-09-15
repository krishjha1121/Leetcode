class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> v(26, 0);
        int result = 0;
        int cnt = 0;

        for(char it : brokenLetters){
            v[it - 'a']++;
        }

        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                result += (cnt == 0);
                cnt = 0;
            }else if(v[text[i] - 'a'] == 1){
                cnt++;
            }
        }

        if(cnt == 0) result++;
        return result;
    }
};