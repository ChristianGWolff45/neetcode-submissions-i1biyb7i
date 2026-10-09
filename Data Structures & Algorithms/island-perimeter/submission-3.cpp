class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return bfs(grid, i, j);
                }
            }
        }
        return perimeter;
    }

    int bfs(vector<vector<int>>& grid, int i, int j){

        queue<pair<int, int>> q;
        q.push({i,j});
        int size = q.size();
        int perimeter = 0;
        grid[i][j] = 2;
        while(!q.empty()){
            size = q.size();
            for(int k = 0; k < size; k++){
                pair coord = q.front(); q.pop();
                i = coord.first;
                j = coord.second;
                if(i > 0 && grid[i - 1][j] == 1){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }else if(i <= 0 || grid[i - 1][j] == 0){
                    perimeter++;
                }
                if(i+1 < grid.size() && grid[i + 1][j] == 1){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }else if(i + 1 >= grid.size() || grid[i + 1][j] == 0){
                    perimeter++;
                }
                if(j > 0 && grid[i][j-1] == 1){
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                }else if(j <= 0 || grid[i][j - 1] == 0){
                    perimeter++;
                }
                if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                    q.push({i, j+1});
                    grid[i][j + 1] = 2;
                }else if(j + 1 >= grid[i].size() || grid[i][j + 1] == 0){
                    perimeter++;
                }
            }
        }
        return perimeter;
    }
};