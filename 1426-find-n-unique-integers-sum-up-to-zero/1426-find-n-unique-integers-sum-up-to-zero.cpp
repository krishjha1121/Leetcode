class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};

        vector<int> temp;

        for(int i = 1; i <= n / 2; i++){
            temp.push_back(i);
        }

        if(n & 1) temp.push_back(0);

        for(int i = 1; i <= n/ 2; i++){
            temp.push_back(-i);
        }

        return temp;
    }
};