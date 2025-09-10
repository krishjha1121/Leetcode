class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> sadUsers;

        for(auto it : friendships){
            int u = it[0];
            int v = it[1];

            // convert to 0-based indexing
            u--;
            v--;

            set<int> langSet(languages[u].begin(), languages[u].end());
            bool canTalk = false;
            for(auto it : languages[v]){
                if(langSet.count(it)){
                    canTalk = true;
                    break;
                }
            }

            // they cannot talk to each other so insert in sadUsers
            if(!canTalk) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        // teach max known language to those who dont know that language
        vector<int> lang(n + 1, 0);
        int maxi = 0;

        // go to every sad user and see which languages they can speak and make a count array
        for(int it : sadUsers){
            for(int knownLang : languages[it]){
                lang[knownLang]++;
                maxi = max(maxi, lang[knownLang]);
            }
        }

        return sadUsers.size() - maxi;
    }
};