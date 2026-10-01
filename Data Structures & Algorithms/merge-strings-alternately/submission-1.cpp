class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string combine;
        combine.reserve(word1.size() + word2.size());
        int w1 = 0, w2 = 0;
        while(w1 < word1.size() && w2 < word2.size()){
            combine.push_back(word1[w1]);
            combine.push_back(word2[w2]);
            w1++;
            w2++;
        }
        combine += word1.substr(w1);
        combine += word2.substr(w2);
        return combine;
    }
};