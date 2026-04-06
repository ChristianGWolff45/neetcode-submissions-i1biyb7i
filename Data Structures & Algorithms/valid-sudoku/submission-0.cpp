class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> group;
        for(const auto& row : board){
            group.clear();
            for(char num : row){
                if(num == '.') continue;
                if(group.count(num)) return false;
                else group.insert(num);
            }
        }
        for(int i = 0; i < board.size(); i++){
            group.clear();
            for(int j = 0; j < board[i].size(); j++){
                if(board[j][i] == '.') continue;
                if(group.count(board[j][i])) return false;
                else group.insert(board[j][i]);
            }
        }
        for(int i = 0; i < board.size(); i++){
            group.clear();
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(board[j+(i%3)*3][k+(i/3)*3] == '.') continue;
                    if(group.count(board[j+(i%3)*3][k+(i/3)*3])) return false;
                    else group.insert(board[j+(i%3)*3][k+(i/3)*3]);
                }
            }
        }
        return true;
    }
};
