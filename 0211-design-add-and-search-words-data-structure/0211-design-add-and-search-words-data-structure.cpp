struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }   
    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* getNext(char ch){
        return links[ch - 'a'];;
    }
    void setFlag(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(Node* node, string& word, int idx){
        if(idx == word.size()) return node -> isEnd();

        char ch = word[idx];
        if(ch != '.'){
            if(!node -> containsKey(ch)) return false;
            return dfs(node -> getNext(ch), word, idx + 1);
        }else{
            for(int i = 0; i < 26; i++){
                if(node -> links[i] != NULL){
                    if(dfs(node -> links[i], word, idx + 1)) return true;
                }
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            if(!temp -> containsKey(word[i])){
                temp -> putKey(word[i], new Node());
            }
            temp = temp -> getNext(word[i]);
        }
        temp -> setFlag();
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */