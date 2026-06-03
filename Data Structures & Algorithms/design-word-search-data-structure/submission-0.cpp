class WordDictionary {
    struct WordNode{
        unordered_map<char, WordNode*> children;
        bool endOfWord = false;
    };
public:
    WordNode* root;
    WordDictionary() {
        root = new WordNode();
    }
    
    void addWord(string word) {
        WordNode* curr = root;
        for(char c : word){
            auto child = curr->children.find(c);

            if(child == curr->children.end()){
                curr->children[c] = new WordNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        bool isMatch = false;
        dfs(word, root, isMatch);
        return isMatch;

    }

    void dfs(string word, WordNode* node, bool& isMatch){
        if(word.length() == 0){
            isMatch = node->endOfWord;
        }
        if(isMatch || word.length() == 0){
            return;
        }
        char c = word[0];
        if(c == '.'){
            for(const auto& pair : node->children){
                dfs(word.substr(1), pair.second, isMatch);
            }
        }else{
            if(node->children.contains(c)){
                dfs(word.substr(1), node->children[c], isMatch);
            }
        }

    }
};
