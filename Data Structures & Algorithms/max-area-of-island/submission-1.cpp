class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        int curSize = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    areaOfIsland(grid, i, j, curSize);
                    if(curSize > maxSize){
                        maxSize = curSize;
                    }
                    curSize = 0;
                }
            }
        }
        return maxSize;
    }
    void areaOfIsland(vector<vector<int>>& grid, int i, int j, int& curSize){
        grid[i][j] = 0;
        curSize++;
        if(i - 1 >= 0){
            if(grid[i-1][j] == 1) areaOfIsland(grid, i -1, j, curSize);
        }
        if(i + 1 < grid.size()){
            if(grid[i + 1][j] == 1) areaOfIsland(grid, i + 1, j, curSize);
        }
        if(j - 1 >= 0){
            if(grid[i][j-1] == 1) areaOfIsland(grid, i , j-1, curSize);
        }
        if(j + 1 < grid[i].size()){
            if(grid[i][j+1] == 1) areaOfIsland(grid, i, j+1, curSize);
        }
        
    }
};
