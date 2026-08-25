class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            for(int i = 0; i < 26; i++){
                child[i] = nullptr;
            }
            word = "";
        }
    };

    int m, n;
    vector<string> res;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        char ch = board[i][j];
        if(ch == '#') return;

        TrieNode* next = node->child[ch - 'a'];
        if(next == nullptr) return;

        if(next->word != ""){
            res.push_back(next->word);
            next->word = "";
        }
        board[i][j] = '#';

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] != '#'){
                dfs(board, ni, nj, next);
            }
        }
        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        TrieNode* root = new TrieNode();

        for(string& word : words){
            TrieNode* node = root;

            for(char ch : word){
                int idx = ch - 'a';
                if(node->child[idx] == nullptr){
                    node->child[idx] = new TrieNode();
                }
                node = node->child[idx];
            }
            node->word = word;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, root);
            }
        }
        return res;
    }
};