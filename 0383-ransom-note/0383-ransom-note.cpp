class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mpp;
        for(char it : magazine){
            mpp[it]++;
        }

        for(char it : ransomNote){
            if(mpp.find(it) != mpp.end()){
                mpp[it]--;
                if(mpp[it] == 0) mpp.erase(it);
            }else{
                return false;
            }
        }

        return true;
    }
};