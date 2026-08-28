class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> letters = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        vector<string> comb;
        string curr;
        if(digits.size() == 0){
            return comb;
        }
        backtrack(comb, curr, digits, 0, letters);

        return comb;
    }
    void backtrack(vector<string>& comb, string curr, string& digits, int index, vector<vector<char>>& letters){
        if(index == digits.size()){
            comb.push_back(curr);
            return;
        }
        int j = digits[index] - '0';
        for(int i = 0; i < letters[j-2].size(); i++){
            curr.push_back(letters[j-2][i]);
            backtrack(comb, curr, digits, index + 1, letters);
            curr.pop_back();
        }
        return;

    }
};
