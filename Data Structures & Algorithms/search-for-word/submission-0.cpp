class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool exists = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    backtrack(board, word, 1, exists, i, j, visited);
                    visited[i][j] = false;
                    if(exists){
                        return true;
                    }
                }
            }
        }


        return exists;
        
    }
    void backtrack(const vector<vector<char>>& board, string word, int index, bool &exists, int i, int j, vector<vector<bool>>& visited){
        if(exists){
            return;
        }
        if(index == word.size()){
            exists = true;
            return;
        }
        
        if(i - 1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[index]){
            visited[i-1][j] = true;
            backtrack(board, word, index + 1, exists, i-1, j, visited);
            visited[i-1][j] = false;

        }if(j - 1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[index]){
            visited[i][j-1] = true;
            backtrack(board, word, index + 1, exists, i, j-1, visited);
            visited[i][j-1] = false;

        }if(i + 1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[index]){
            visited[i+1][j] = true;
            backtrack(board, word, index + 1, exists, i+1, j, visited);
            visited[i+1][j] = false;

        }if(j + 1 < board[i].size() && !visited[i][j+1] && board[i][j+1] == word[index]){
            visited[i][j+1] = true;
            backtrack(board, word, index + 1, exists, i, j+1, visited);
            visited[i][j+1] = false;

        }

    }
};
