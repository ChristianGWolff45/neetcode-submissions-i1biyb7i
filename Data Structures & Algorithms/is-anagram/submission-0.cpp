class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> letters;
        for(char c : s){
            letters[c]++;
        }
        for(char c : t){
            if(!letters.count(c)) return false;
            letters[c]--;
            if(letters[c] == 0) letters.erase(c);
        }
        return letters.empty();
    }
};
