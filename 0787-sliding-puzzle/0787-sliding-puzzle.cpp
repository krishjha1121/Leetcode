class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i= 0 ; i < 2 ; i++){
            for(int j = 0 ;j < 3 ; j++){
                start += to_string(board[i][j]);
            }
        }
        string target = "123450";
        queue<string> q;
        q.push(start);
        map<int , vector<int>> mpp;
        mpp[0] = {1 , 3};
        mpp[1] = {0 , 2 , 4};
        mpp[2] = {1 , 5};
        mpp[3] = {0 , 4};
        mpp[4] = {1 , 3 , 5};
        mpp[5] = {2 , 4};
        set<string> vis;
        vis.insert(start);
        q.push(start);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return cnt;
                }
                int currIndex = curr.find('0');
                for(auto validIndex : mpp[currIndex]){
                    string newString = curr;
                    swap(newString[currIndex] , newString[validIndex]);

                    if(vis.find(newString) == vis.end()){
                        q.push(newString);
                        vis.insert(newString);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};