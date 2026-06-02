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
        for(char c : word){
            if(!(curr->children.contains(c))){
                curr->children[c] = new PrefixNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
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
        return (curr->endOfWord);
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
