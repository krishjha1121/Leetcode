class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
        }
        int rem = moves.size() - l - r;
        int res = max((l - r + rem), (r - l + rem));
        return res;
    }
};