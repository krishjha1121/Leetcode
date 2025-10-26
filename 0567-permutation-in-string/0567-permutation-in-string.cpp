class Solution {
public:
    bool check(vector<int> &a , vector<int> &b){
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> freq(26 , 0);
        for(auto it : s1){
            freq[it - 'a']++;
        }
        vector<int> freq2(26 , 0);
        int i = 0;
        int j = 0;
        while(j < s2.size()){
            freq2[s2[j] - 'a']++;
            if(j - i + 1 == s1.size()){
                bool flag = check(freq, freq2);
                if(flag) return true;
            }
            if(j - i + 1 < s1.size()){
                j++;
            }
            else{
                freq2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};