class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    dfs(perimeter, grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
    void dfs(int& perimeter, vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 2;
        if(i > 0 && grid[i - 1][j] == 1){
            dfs(perimeter, grid, i-1, j);
        }else if(i <= 0 || grid[i - 1][j] == 0){
            perimeter++;
        }
        if(i+1 < grid.size() && grid[i + 1][j] == 1){
            dfs(perimeter, grid, i+1, j);
        }else if(i + 1 >= grid.size() || grid[i + 1][j] == 0){
            perimeter++;
        }
        if(j > 0 && grid[i][j-1] == 1){
            dfs(perimeter, grid, i, j-1);
        }else if(j <= 0 || grid[i][j - 1] == 0){
            perimeter++;
        }
        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
            dfs(perimeter, grid, i, j+1);
        }else if(j + 1 >= grid[i].size() || grid[i][j + 1] == 0){
            perimeter++;
        }
    }
};