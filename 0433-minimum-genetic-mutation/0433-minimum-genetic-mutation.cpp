class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;
        int steps = 0;
        q.push(startGene);
        visited.insert(startGene);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                if(node == endGene) return steps;
                for(int i = 0; i < 8; i++){ 
                    char ogChar = node[i];
                    for(char c : string("ACGT")){ 
                        if(c == ogChar) continue;
                        node[i] = c;
                        if(!visited.count(node) && bankSet.count(node)){
                            q.push(node);
                            visited.insert(node);
                        }
                    }
                    node[i] = ogChar;
                }
            }
            steps++;
        }
        return -1;
    }
};
