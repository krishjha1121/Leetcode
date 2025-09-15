class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        for(auto it : brokenLetters){
            st.insert(it);
        }

        int cnt = 0;
        for(int i = 0; i < text.size(); i++){
            string temp = "";

            while(text[i] != ' ' && i < text.size()){
                temp += text[i];
                i++;
            }

            cout << temp << endl;
            bool flag = false;
            for(int k = 0; k < temp.size(); k++){
                if(st.find(temp[k]) != st.end()){
                    flag = true;
                    break;
                }
            }       

            if(!flag) cnt++;
        }

        return cnt;
    }
};