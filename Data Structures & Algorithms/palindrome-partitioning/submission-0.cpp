class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromeSubstrings;
        vector<string> palindromeSubstring;
        backtrack(palindromeSubstrings, palindromeSubstring, "", 0, s);

        return palindromeSubstrings;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& curSubstring, string current, int index, string s){
        if(index == s.size()){
            if(isPalindrome(current)){
                curSubstring.push_back(current);
                res.push_back(curSubstring);
                curSubstring.pop_back();
            }
            return;
        }
        current.push_back(s[index]);
        
        backtrack(res, curSubstring, current, index+1, s);
        
        if(isPalindrome(current)){
            curSubstring.push_back(current);
            current = "";
            backtrack(res, curSubstring, current, index+1, s);
            curSubstring.pop_back();
        }
    }

    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return s.size();
    }
};
