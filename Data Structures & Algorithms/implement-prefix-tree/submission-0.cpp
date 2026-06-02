class PrefixTree {
    struct PrefixNode {
        unordered_map<char, PrefixNode*> children;
        bool endOfWord = false;
    };
    PrefixNode* root;
public:
    PrefixTree() {
        root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!(curr->children.contains(word[i]))){
                curr->children[word[i]] = new PrefixNode();
            }
            curr = curr->children[word[i]];
            if(i == word.length() - 1){
                curr->endOfWord = true;
            }
        }
    }
    
    bool search(string word) {
        PrefixNode* curr = root;
        for(char c : word){
            if(curr->children.contains(c)){
                curr = curr->children[c];
            }else{
                return false;
            }
        }
        if(curr->endOfWord) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* curr = root;
        for(char c : prefix){
            if(curr->children.contains(c)){
                curr = curr->children[c];
            }else{
                return false;
            }
        }
        return true;
    }
};
