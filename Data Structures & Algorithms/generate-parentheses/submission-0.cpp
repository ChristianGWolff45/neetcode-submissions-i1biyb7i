class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        string current = "(";
        backtrack(parenthesis, n, current, 1);
        return parenthesis;
    }
    void backtrack(vector<string>& parenthesis, int n, string current, int parenthesisCount){
        if(parenthesisCount == n){
            int i = 0;
            while(current.length() < n * 2){
                current.push_back(')');
                i++;
            }
            parenthesis.push_back(current);
            return;
        }
        if((parenthesisCount * 2) - current.length() > 0){
            current.push_back(')');
            backtrack(parenthesis, n, current, parenthesisCount);
            current.pop_back();
        }
        current.push_back('(');
        backtrack(parenthesis, n, current, parenthesisCount + 1);
    }
};
