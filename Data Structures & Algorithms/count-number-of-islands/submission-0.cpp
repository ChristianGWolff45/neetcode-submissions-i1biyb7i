class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j< grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            } 
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = 'X';
        if(i-1 >= 0){
            if(grid[i-1][j] == '1') dfs(grid, i-1, j);
        }
        if(i+1 < grid.size()){
            if(grid[i+1][j] == '1') dfs(grid, i+1, j);
        }
        if(j-1 >= 0){
            if(grid[i][j-1] == '1') dfs(grid, i, j-1);
        }
        if(j+1 < grid[i].size()){
            if(grid[i][j+1] == '1') dfs(grid, i, j+1);
        }
    }
};
